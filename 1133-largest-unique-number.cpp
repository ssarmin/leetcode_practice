//https://leetcode.com/problems/largest-unique-number
class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n: nums){
            m[n]++;
        }
        int max_val = INT_MIN;
        for(auto a: m){
            if(a.second == 1){
                max_val = max(max_val, a.first);
            }
        }
        return max_val == INT_MIN? -1: max_val;
    }
};
