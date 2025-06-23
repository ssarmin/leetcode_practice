//https://leetcode.com/problems/majority-element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n: nums){
            m[n]++;
        }
        int max_num = 0;
        int max_val;
        for(auto &it: m){
            if(it.second > max_num){
                max_num = it.second;
                max_val = it.first;
            }
        }

        return max_val;
    }
};
