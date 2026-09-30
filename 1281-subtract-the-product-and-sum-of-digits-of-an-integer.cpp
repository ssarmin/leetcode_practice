//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
class Solution {
public:
    int subtractProductAndSum(int n) {
        if(n==0)
            return 0;
        int sum = 0;
        int mul = 1;
        while(n){
            int digit = n%10;
            n = n/10;
            sum += digit;
            mul *= digit;
        }

        return mul - sum;
    }
};
/*
100000
99999
*/
