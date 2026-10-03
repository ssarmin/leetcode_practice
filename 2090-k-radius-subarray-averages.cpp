//https://leetcode.com/problems/k-radius-subarray-averages/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)
            return nums;
        vector<int> res(nums.size(), -1);
        if(k*2+1 > nums.size()){
            return res;
        }
        long long left = 0;
        long long right = 0;
        for(int i=0; i<k; i++){
            left += nums[i];
            right += nums[i+k+1];
        }
        int div_by = k*2 + 1;
        for(int i=k; i<nums.size()-k; i++){
            res[i] = (left + right + nums[i])/div_by;
            left -= nums[i-k];
            left += nums[i];

            right -= nums[i+1];
            if(i+k+1 < nums.size())
                right += nums[i+k+1];
        }
        return res;
    }
};
/*
[40527,53696,10730,66491,62141,83909,78635,18560]
2
*/
