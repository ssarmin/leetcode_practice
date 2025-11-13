//https://leetcode.com/problems/n-th-tribonacci-number
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        int t_0 = 0, t_1 = 1, t_2 = 1;
        for(int i=3; i<=n; i++){
            int sum = t_0 + t_1 + t_2;
            t_0 = t_1;
            t_1 = t_2;
            t_2 = sum;
        }
        return t_2;
    }
};
//37
