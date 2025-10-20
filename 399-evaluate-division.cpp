//https://leetcode.com/problems/evaluate-division
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0; i<values.size(); i++){
            vector<string> e = equations[i];
            m[e[0]][e[1]] = values[i];
            m[e[1]][e[0]] = 1/values[i];
        }

        vector<double> res;
        for(auto q: queries){
            if(m.count(q[0]) && m.count(q[1])){
                if(q[0] == q[1])
                    res.push_back(1.0);
                else{
                    if(m[q[0]].count(q[1]))
                        res.push_back(m[q[0]][q[1]]);
                    else{
                        queue<pair<string, double>> _queue;
                        _queue.push({q[0], 1.0});
                        unordered_set<string> visit;
                        bool flag = false;
                        visit.insert(q[0]);
                        while(!_queue.empty()){
                            int size = _queue.size();
                            while(size--){
                                string node = _queue.front().first;
                                double val = _queue.front().second;
                                _queue.pop();
                                for(auto a: m[node]){
                                    if(a.first == q[1]){
                                        res.push_back(val*a.second);
                                        flag = true;
                                        m[q[0]][q[1]] = val*a.second;
                                        m[q[1]][q[0]] = 1/m[q[0]][q[1]];
                                        break;
                                    }else{
                                        if(visit.count(a.first))
                                            continue;
                                        visit.insert(a.first);
                                        _queue.push({a.first, val*a.second});
                                    }
                                }
                                if(flag)
                                    break;
                            }
                            if(flag)
                                break;
                        }
                        if(!flag){
                            res.push_back(-1.0);
                        }
                    }
                }
            }else{
                res.push_back(-1.0);
            }
        }
        return res;
    }
};
// [["a","b"],["c","d"]]
// [1.0,1.0]
// [["a","c"],["b","d"],["b","a"],["d","c"]]
// [["a","b"]]
// [0.5]
// [["a","b"],["b","a"],["a","c"],["x","y"]]
// [["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]
// [2.0,3.0,4.0,5.0,6.0,7.0,8.0]
// [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","z"]]
// [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
// [3.0,4.0,5.0,6.0]
// [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]
// [["a","b"],["b","c"],["bc","cd"]]
// [1.5,2.5,5.0]
// [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// [ ["a","b"],["b","c"] ]
// [2.0,3.0]
// [ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]
// [["a","b"]]
// [0.5]
// [["a","b"],["b","a"],["a","c"],["x","y"]]
// [["a","b"],["b","c"],["bc","cd"]]
// [1.5,2.5,5.0]
// [["a","c"],["c","b"],["bc","cd"],["ac","cd"]]
// [["ab","cd"],["a","c"]]
// [4.0,2.0]
// [["b","d"]]
// [["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]
// [2.0,3.0,4.0,5.0,6.0,7.0,8.0]
// [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","z"]]
// [["a","b"],["b","c"],["a","c"]]
// [2.0,3.0,6.0]
// [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// [["a","b"],["b","c"]]
// [2.0,3.0]
// [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// [["a","b"],["b","c"],["bc","cd"]]
// [1.5,2.5,5.0]
// [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// [["a","b"]]
// [0.5]
// [["a","b"],["b","a"],["a","c"],["x","y"]]
// [["a","b"]]
// [0.5]
// [["a","b"],["b","a"],["a","c"],["x","y"]]
// [["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]
// [2.0,3.0,4.0,5.0,6.0,7.0,8.0]
// [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","z"]]
// [["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
// [3.0,4.0,5.0,6.0]
// [["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]
// [["a","b"],["b","c"],["bc","cd"]]
// [1.5,2.5,5.0]
// [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// [ ["a","b"],["b","c"] ]
// [2.0,3.0]
// [ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]
