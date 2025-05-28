//https://leetcode.com/problems/product-of-array-except-self/description/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right;
        left.push_back(1);
        right.push_back(1);
        
        for(int i=0; i<nums.size()-1; i++){
            left.push_back(nums[i] * left[left.size()-1]);
        }

        for(int i=nums.size()-1; i>0; i--){
            right.push_back(nums[i] * right[right.size()-1]);
        }

        reverse(right.begin(), right.end());
        for(int i=0; i<nums.size(); i++){
            left[i] = left[i]*right[i];
        }
        return left;
    }
};

// Extra testcase:
// [1,2,3,2,4,6,2,1,5,3,0,20, 2,0, 4]
// [-1,1,0,3,5,6,3,2,5,7,-3,3]
