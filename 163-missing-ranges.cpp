//https://leetcode.com/problems/missing-ranges
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0)
            return {{lower, upper}};
        vector<vector<int>> res;
        for(auto a: nums){
            if(a != lower){
                res.push_back({lower, a-1});
            }
            lower = a+1;
        }
        if(nums.back() != upper){
            res.push_back({lower, upper});
        }
        return res;
    }
};
/*
[-1]
-2
0
[0,1,3,50,75]
-1
99
[1,3,50,75]
0
99
[]
1
1*/
