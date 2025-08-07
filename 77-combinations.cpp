//https://leetcode.com/problems/combinations
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        stack<pair<int, vector<int>>> s;
        s.push({0, {}});

        while(!s.empty()){
            auto [num, v] = s.top();
            s.pop();

            if(v.size() == k){
                res.push_back(v);
                continue;
            }

            while(num < n){
                num++;
                v.push_back(num);
                s.push({num, v});
                v.pop_back();
            }
        }

        return res;
    }
};
// 20
// 5
