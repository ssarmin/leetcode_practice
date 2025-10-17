//https://leetcode.com/problems/permutations
class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &res, int index){
        if(index >= nums.size()){
            res.push_back(nums);
        }else{
            for(int i=index; i<nums.size(); i++){
                swap(nums[i], nums[index]);
                helper(nums, res, index+1);
                swap(nums[i], nums[index]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, res, 0);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        stack<tuple<vector<int>, int, int>> s;
        s.push({nums, 0, nums.size()-1});

        while(!s.empty()){
            auto [nums, start, end] = s.top();
            s.pop();
            res.push_back(nums);
            while(start < end){
                for(int i=start+1; i<=end; i++){
                    swap(nums[i], nums[start]);
                    s.push({nums, start+1, end});
                    swap(nums[i], nums[start]);
                }
                start++;
            }
        }
        return res;
    }
};


// [1,2,3,4,5,7]
