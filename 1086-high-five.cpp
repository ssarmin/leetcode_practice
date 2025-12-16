//https://leetcode.com/problems/high-five
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> m;
        for(auto item: items){
            m[item[0]].push(item[1]);
        }
        vector<vector<int>> res;
        for(auto a: m){
            int val = 0;
            for(int i=0; i<5; i++){
                val += a.second.top();
                a.second.pop();
            }
            res.push_back({a.first, val/5});
        }
        return res;
    }
};
