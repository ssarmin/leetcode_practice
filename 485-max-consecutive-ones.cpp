//https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for(auto n: nums){
            if(n == 1){
                count++;
            }else{
                res = max(res, count);
                count = 0;
            }
        }
        res = max(res, count);
        return res;
    }
};
