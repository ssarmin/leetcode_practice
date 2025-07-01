// https://leetcode.com/problems/single-number-ii
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<32; i++){
            int sum = 0;
            for(auto n: nums){
                sum += (n >> i) & 1;
            }

            res += (sum%3) << i;
        }

        return res;
    }
};

// [-2147483648, -2147483648, -2147483648, 2147483647]
// [2147483647]
