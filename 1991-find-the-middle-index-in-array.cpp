//https://leetcode.com/problems/find-the-middle-index-in-array
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> pre_sum;
        pre_sum.resize(nums.size());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<nums.size(); i++){
            if(i == 0){
                pre_sum[i] = 0;
            }else{
                pre_sum[i] = pre_sum[i-1] + nums[i-1];
            }
            int right = sum - nums[i] - pre_sum[i];
            if(pre_sum[i] == right)
                return i; 
        }
        return -1;
    }
};
