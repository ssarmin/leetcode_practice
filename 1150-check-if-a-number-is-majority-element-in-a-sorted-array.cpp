//https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        for(auto n: nums){
            if(n == target){
                count++;
            }
        }
        return count > nums.size()/2;
    }
};
