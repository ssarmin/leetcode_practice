//https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &v, const vector<int> &nums, int index){
        res.push_back(v);
        for(int i=index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1])continue;
            v.push_back(nums[i]);
            helper(res, v, nums, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(res, v, nums, 0);
        return res;
    }
};

// [1,2,2,4,6,3,4,2,4,4]
