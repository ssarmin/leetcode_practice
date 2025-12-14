//https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int large_sum = 0;
        int small_sum = 0;
        int index = nums.size()-1;
        for(int i=0; i<k; i++){
            small_sum += nums[i];
            large_sum += nums[index];
            index--;
        }
        return abs(large_sum - small_sum);
    }
};
