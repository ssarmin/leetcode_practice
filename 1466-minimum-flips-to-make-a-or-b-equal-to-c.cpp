//https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a || b || c){
            int bit_a = (a&1);
            int bit_b = (b&1);
            int bit_c = (c&1);

            a = a>>1;
            b = b>>1;
            c = c>>1;
            if((bit_a || bit_b) != bit_c){
                if(bit_c == 0){
                    count += bit_a;
                    count += bit_b;
                }else{
                    count += 1;
                }
            }
        }
        return count;
    }
};

// 7
// 3
// 9
// 1000000000
// 999999999
// 112323456
