//https://leetcode.com/problems/minimum-size-subarray-sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int total = 0;
        int minSize = INT_MAX;
        while(right < nums.size()){
            if(total < target){
                total += nums[right];
                right++;
            }else{
                minSize = min(minSize, (right - left));
                total -= nums[left];
                left++;
            }
        }

        while(total >= target && left < nums.size()){
            minSize = min(minSize, (right - left));
            total -= nums[left];
            left++;
        }

        if(minSize == INT_MAX)
        return 0;
        return minSize;
    }
};
