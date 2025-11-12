//https://leetcode.com/problems/maximum-product-subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_val = nums[0];
        vector<int> max_v, min_v;
        max_v.resize(nums.size());
        min_v.resize(nums.size());
        min_v[0] = max_val;
        max_v[0] = max_val;
        for(int i=1; i < nums.size(); i++){
            if(nums[i] == 0){
                min_v[i] = 0;
                max_v[i] = 0;
            }else{
                max_v[i] = nums[i];
                min_v[i] = nums[i];
                if(nums[i-1] != 0){
                    max_v[i] = max(min_v[i-1]*nums[i], max_v[i]);
                    max_v[i] = max(max_v[i-1]*nums[i], max_v[i]);

                    min_v[i] = min(min_v[i-1]*nums[i], min_v[i]);
                    min_v[i] = min(max_v[i-1]*nums[i], min_v[i]);
                }
            }
            max_val = max(max_val, max_v[i]);
        }
        return max_val;
    }
};

[2,-2,0,-1,3,-2,0,-1,-2,4]
[-3,0,1,-2]
[2,3,-2,4]
[-2,0,-1]
[-3,-1,-1]
[-3,0,1,-2]
[7,-2,-4]
[7,-2,5,-4]
[2,-5,-2,-4,3]
[2,-5,-2,-4,-6,3]
[2,-5,-2,8,-4,-6,3]
[-1,-2,-3,0]
