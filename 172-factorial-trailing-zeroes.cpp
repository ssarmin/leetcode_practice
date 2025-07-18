https://leetcode.com/problems/factorial-trailing-zeroes
class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5)
            return 0;
        int count = 0;
        for(int i=5; i<=n; i = i*5){
            count += n/i;
        }

        return count;
    }
};
// 1000
