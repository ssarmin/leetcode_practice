//https://leetcode.com/problems/sum-of-two-integers
class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        for(int i=0; i<32; i++){
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int bit = carry & ((a_bit & b_bit) | (~a_bit & ~b_bit));
            bit = bit | (~carry & (a_bit ^ b_bit));
            carry = (carry & (a_bit ^ b_bit)) | (a_bit & b_bit);
            res = res | bit << i;
        }
        return res;
    }
};
// 1000
// 1000
// -1000
// -1000
// 1000
// -1000
// -14
// 16
