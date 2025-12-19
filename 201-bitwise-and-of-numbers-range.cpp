//https://leetcode.com/problems/bitwise-and-of-numbers-range
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left < right){
            count++;
            left = left >> 1;
            right = right >> 1;
        }

        left = left << count;
        return left;
    }
};
/*
416
436
2
25
14
28
43
60
25
35
4194304
134217709
536870913
1073741804
2097152
8388583
268435456
1073741822
214748364
2147483647
2147483646
2147483647
1073741832
2147483647
*/
// If left is 26 and right 30, then the result would be 11000. Only the leftmost 2 bits are common.
// So, here by right shifting both left and right, we discard all different bits. We stop when both are 11. 
// Then we put zeros on the rightmost bits.

// 26 = 11010  
// 27 = 11011  
// 28 = 11100  
// 29 = 11101  
// 30 = 11110  

// | Step | left | right | Binary (left) | Binary (right) | shift |
// | ---- | ---- | ----- | ------------- | -------------- | ----- |
// | 0    | 26   | 30    | `11010`       | `11110`        | 0     |
// | 1    | 13   | 15    | `01101`       | `01111`        | 1     |
// | 2    | 6    | 7     | `00110`       | `00111`        | 2     |
// | 3    | 3    | 3     | `00011`       | `00011`        | 3 ✅   |


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for(int i=0; i<32; i++){
            bool flag = false;
            for(long n=left; n<=right; n++){
                if(!((n >> i) &1)){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                res += 1 << i;
            }
        }

        return res;
    }
};

// Got TLE for this solution
