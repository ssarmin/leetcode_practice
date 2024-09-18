//https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = 0;
        for(int i=1; i<=nums.size(); i++){
            n = n ^ i;
        }
        for(auto a: nums){
            n = n ^ a;
        }
        return n;
    }
};
//Time complexity: O(N)
