//https://leetcode.com/problems/two-sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                return {m[nums[i]], i};
            }
            m[target-nums[i]] = i;
        }
        return {};
    }
};

/*
[-1000000000,-1000000000,0,-2]
-2
[3,2,4]
6
*/
