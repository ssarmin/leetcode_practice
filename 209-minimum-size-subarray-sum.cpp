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
/*
20
[2,16,14,15]
11
[1,2,3,4,5]
7
[2,2,3,4,3]
15
[1,2,3,4,5]
213
[12,28,83,4,25,26,25,2,25,25,25,12]
80
[10,5,13,4,8,4,5,11,14,9,16,10,20,8]
6
[10,2,3]
*/
