//https://leetcode.com/problems/count-integers-with-even-digit-sum/
class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for(int i=1; i<=num; i++){
            int n=i;
            int sum = 0;
            while(n){
                sum += n%10;
                n = n/10;
            }
            if(sum%2 == 0){
                res++;
            }
        }
        return res;
    }
};
