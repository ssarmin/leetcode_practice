//https://leetcode.com/problems/move-zeroes/description/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unsigned int index = 0;
        for(unsigned int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }else{
                nums[index] = nums[i];
                index++;
            }
        }
        for(; index<nums.size(); index++){
            nums[index] = 0;
        }
    }
};
//Time complexity: O(N)
