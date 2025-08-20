//https://leetcode.com/problems/sqrtx
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x; //early return	Avoids unnecessary computation for small inputs
        int start = 0;
        int end = x/2; //No need to check up to x since √x ≤ x/2 when x ≥ 4
        int index = 0;

        while(start <= end){
            int mid = (end - start)/2 + start;
            unsigned long val = 1UL * mid * mid; //Prevents integer overflow safely
            if(val == x)
                return mid;
            else if(val > x){
                end = mid-1;
            }else{
                start = mid+1;
                index = mid;
            }
        }
        return index;
    }
};
// 423456246
// 83452452
// 2147483647
// 214748364
// 2147483640
// 0
// 1
// 214748647
//2
//3
