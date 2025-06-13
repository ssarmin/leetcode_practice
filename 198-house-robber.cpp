//https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> v(nums.size(), 0);

        v[0] = nums[0];
        v[1] = nums[1];

        for(int i = 2; i < nums.size(); i++){
            if(i == 2)
                v[i] = nums[i] + v[i-2];
            else
                v[i] = nums[i] + max(v[i-2], v[i-3]);
        }

        return max(v[nums.size()-1], v[nums.size()-2]);
    }
};


// Extra testcases:
// [2,7,9,3,0,21,2,3,11]
// [2,1,1,2]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
// [8, 9, 9, 4, 10, 5, 6, 9, 7, 9]
// [1,1,1]
