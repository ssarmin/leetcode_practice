//https://leetcode.com/problems/smallest-string-with-swaps
class Solution {
public:
    vector<int> dfs(int i, unordered_set<int> &visit, unordered_map<int, unordered_set<int>> &m){
        queue<int> q;
        q.push(i);
        vector<int> res;
        while(!q.empty()){
            i = q.front();
            q.pop();
            if(visit.count(i))continue;
            res.push_back(i);
            visit.insert(i);
            for(auto a: m[i]){
                if(!visit.count(a)){
                    q.push(a);
                }
            }
        }
        return res;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> m;
        for(auto p: pairs){
            m[p[0]].insert(p[1]);
            m[p[1]].insert(p[0]);
        }
        unordered_set<int> visit;
        for(int i=0; i<s.size(); i++){
            if(!visit.count(i)){
                vector<int> res = dfs(i, visit, m);
                vector<char> v_temp;
                for(auto index: res){
                    v_temp.push_back(s[index]);
                }
                sort(res.begin(), res.end());
                sort(v_temp.begin(), v_temp.end());
                int k=0;
                for(auto index: res){
                    s[index] = v_temp[k];
                    k++;
                }
            }
        }
        return s;
    }
};

"udyyek"
[[3,3],[3,0],[5,1],[3,1],[3,4],[3,5]]
"qdwyt"
[[2,3],[3,2],[0,1],[4,0],[3,2]]
"dcab"
[]
"pwqlmqm"
[[5,3],[3,0],[5,1],[1,1],[1,5],[3,0],[0,2]]
"fqtvkfkt"
[[2,4],[5,7],[1,0],[0,0],[4,7],[0,3],[4,1],[1,3]]
"otilzqqoj"
[[2,3],[7,3],[3,8],[1,7],[1,0],[0,4],[0,6],[3,4],[2,5]]
"zbxxxdgmbz"
[[1,0],[7,1],[9,1],[3,0],[7,1],[0,4],[6,5],[2,6],[6,4],[6,0]]
"vbjjxgdfnru"
[[8,6],[3,4],[5,2],[5,5],[3,5],[7,10],[6,0],[10,0],[7,1],[4,8],[6,2]]
"tklkxyizmlqf"
[[2,10],[3,5],[8,11],[1,2],[10,6],[4,1],[1,10],[5,8],[8,3],[10,4],[7,3],[10,11]]

 
