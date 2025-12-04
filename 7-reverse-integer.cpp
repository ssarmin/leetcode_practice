// https://leetcode.com/problems/reverse-integer
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == INT_MAX)
            return 0;
        bool neg = false;
        if(x < 0){
            neg = true;
            x = abs(x);
        }
        long long val = 0;
        while(x){
            val = val*10 + x%10;
            x = x/10;
            if(val > INT_MAX){
                return 0;
            }
            if(neg && val -1 > INT_MAX){
                return 0;
            }
        }
        return (neg)? -1*(int)val: (int)val;
    }
};

/*
1534236469
1563847412
-1563847412
-1036
-2147483648
-846384742
*/
