//https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i].size() >= target.size())continue;
            for(int j=i+1; j<nums.size(); j++){
                if(target == (nums[i]+nums[j]))
                    res++;
                if(target == (nums[j]+nums[i]))
                    res++;
            }
        }
        return res;
    }
};
/*
["9","93","9","2","32","32"]
"932"
*/
