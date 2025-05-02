// https://leetcode.com/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int val_index = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                if(val_index == -1){
                    val_index = i;
                }
            }else{
                if(val_index != -1){
                    swap(nums[val_index], nums[i]);
                    val_index++;
                }
            }
        }
        if(val_index == -1)
            return nums.size();
        return val_index;
    }
};


// [0,1,2,2,3,0,4,2,23,5,3,5,3,2,4,5,2]
// 2

// [0]
// 2

// [2,2]
// 2

// [3,2,2]
// 3
