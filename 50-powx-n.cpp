//https://leetcode.com/problems/powx-n
class Solution {
public:
    double helper(double x, long n, unordered_map<long, double> &m){
        if(n == 0)
            return 1.0;
        if(x == 0 || x == 1)
            return x;
        if(m.find(n) != m.end())
            return m[n];
        if(n%2 == 0){
            double val = helper(x, n/2, m);
            m[n] = val*val;
        }else{
            double val = helper(x, n/2, m);
            m[n] = x*val*val;
        }
        return m[n];
    }
    double myPow(double x, int n) {
        if(n == 0)
            return 1.0;
        if(x == 0 || x == 1)
            return x;
        long new_n = n;
        if(new_n < 0){
            x = 1.0/x;
            new_n = abs(new_n);
        }
        unordered_map<long, double> m;
        double val = helper(x, new_n, m);
        return m[new_n];
    }
};
// 0.44528
// 0
// 1.0000001
// -2147483648
// 8.88023
// 3
// 2.1
// 3
// 1.00000
// -2147483648
// 1.00000
// 2147483647
