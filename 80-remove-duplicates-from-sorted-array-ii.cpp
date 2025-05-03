//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev_val = nums[0];
        int count = 1;
        int index = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == prev_val){
                count++;
            }else{
                prev_val = nums[i];
                count = 1;
            }
            if(count <= 2){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
// Extra testcases:
// [1,1,1,2,2,2,3,3,3]
// [1,1]
// [1]
// [1,1,1]
