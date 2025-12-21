//https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]] += cost[i];
        }
        long long max_val = 0;
        char ch;
        for(auto a: m){
            max_val = max(max_val, a.second);
            if(max_val == a.second){
                ch = a.first;
            }
        }
        long long res = 0;
        for(auto a: m){
            if(a.first == ch)continue;
            res += a.second;
        }
        return res;
    }
};
