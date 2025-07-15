//https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
        int max_val = nums[0];
        if(nums.size() <= 3){
            for(int i=1; i<nums.size(); i++){
                max_val = max(max_val, nums[i]);
            }
            return max_val;
        }
        int val1 = nums[0];
        int val2 = max(nums[1], nums[0]);
        for(int i=2; i<nums.size()-1; i++){
            int val = max(nums[i] + val1, val2);
            val1 = val2;
            val2 = val;
        }
        max_val = max(max_val, val2);

        val1 = nums[1];
        val2 = max(nums[1], nums[2]);
        for(int i=3; i<nums.size(); i++){
            int val = max(nums[i] + val1, val2);
            val1 = val2;
            val2 = val;
        }
        max_val = max(max_val, val2);
        
        return max_val;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)

// [2,3,2]
// [1,2,3,1]
// [1,2,3]
// [1,2,1,1]
// [1,2,3,4,5,1,2,3,4,5]
// [200,3,140,20,10]
// [1]
// [94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72]
// [2,7,9,3,0,21,2,3,11]
// [2,1,1,2]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
// [8, 9, 9, 4, 10, 5, 6, 9, 7, 9]
// [1,1,1]
// [1,3,1,3,100]
