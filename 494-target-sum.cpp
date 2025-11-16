//https://leetcode.com/problems/target-sum
class Solution {
public:
    int helper(vector<int> &nums, unordered_map<int, unordered_map<int, int>> &m, int target, int index, int curr_sum){
        if(index >= nums.size()){
            return curr_sum == target? 1: 0;
        }
        if(m.count(index) && m[index].count(curr_sum)){
            return m[index][curr_sum];
        }
        m[index][curr_sum] = helper(nums, m, target, index+1, curr_sum + nums[index]) + helper(nums, m, target, index+1, curr_sum - nums[index]);
        return m[index][curr_sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> m;//index, curr_sum, res
        return helper(nums, m, target, 0, 0);
    }
};
/*
[1,0]
1
[100,100]
-300
[12,25,42,49,41,15,22,34,28,31]
35
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
1
[3,2,3,5,7,11,13,17,19,23,29,2,7,9,13,27,31,37,47,53]
107
[0,5,22,39,30,5,40,23,47,43,19,36,10,28,46,14,11,5,50,41]
48
[30,29,48,14,29,4,31,12,40,13,30,1,5,32,16,17,13,20,41,38]
9
[3,2,3,5,7,11,13,17,19,23,29,2,107,109,113,127,131,137,47,53]
4
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
0
[1,2,1]
0
[1,2,3,4,5]
3
[2,3,5,6]
1
[18,50,26,2,15,14,14,2,42,43,38,44,24,17,19,25,3,10,42,20]
24
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
10
*/
