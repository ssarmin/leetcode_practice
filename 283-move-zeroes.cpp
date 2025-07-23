//https://leetcode.com/problems/move-zeroes
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int index = 0;
        for(; index<nums.size(); index++){
            if(nums[index] == 0){
                continue;
            }
            nums[i] = nums[index];
            i++;
        }
        while(i < nums.size()){
            nums[i] = 0;
            i++;
        }
    }
};

// [16601,78714,11653,-45162,0,-22859,0,36007,19143,-91750,0,-45361,-10715,46528,-91518,-36985,59578,76628,-87592,89803,0,-41430,44290,59831,41824,-30916,-6521,61614,46035,39346,0,0,32417]
// [45192,0,-659,-52359,-99225,-75991,0,-15155,27382,59818,0,-30645,-17025,81209,887,64648]
// [0, 0, 0, 0, 0, 0, 1]
