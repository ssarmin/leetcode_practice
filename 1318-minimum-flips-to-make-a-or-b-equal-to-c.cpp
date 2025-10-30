https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i=0; i<32; i++){
            int c_bit = (c >> i) & 1;
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            if((a_bit | b_bit) != c_bit){
                if(a_bit == 1 && b_bit == 1){
                    count += 2;
                }else{
                    count++;
                }
            }
        }
        return count;
    }
};
// 58076
// 49567
// 394506
