//https://leetcode.com/problems/domino-and-tromino-tiling
class Solution {
public:
    int numTilings(int n) {
        int MOD = 1000000007;
        if(n <= 2)
            return n;
        vector<int> f(n+1, 0);
        vector<int> p(n+1, 0);//partial cover
        f[1] = 1;
        f[2] = 2;
        p[2] = 1;
        for(int i=3; i<=n; i++){
            p[i] = (f[i-2] + p[i-1])%MOD;
            f[i] = (f[i-1] + f[i-2])%MOD;
            f[i] = (f[i] + p[i-1])%MOD;
            f[i] = (f[i] + p[i-1])%MOD;
        }
        return f[n];
    }
};
//40
//1000
