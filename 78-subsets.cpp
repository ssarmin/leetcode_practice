// https://leetcode.com/problems/subsets

class Solution {
public:
    void helper(vector<int> &nums, vector<int> &v, vector<vector<int>> &res, int index){
        res.push_back(v);
        for(int i=index; i<nums.size(); i++){
            v.push_back(nums[i]);
            helper(nums, v, res, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        helper(nums, v, res, 0);
        return res;
    }
};
// [2,3,4,5,7,9,0,-1,-2,-3]
