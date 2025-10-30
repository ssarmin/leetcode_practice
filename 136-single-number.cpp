//https://leetcode.com/problems/single-number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums[0];
        for(int i=1; i<nums.size(); i++){
            n = n ^ nums[i];
        }
        return n;
    }
};
// [-2,-2,1]
// [-4,1,2,1,2]
// [-1]
