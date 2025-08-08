//https://leetcode.com/problems/permutations
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
