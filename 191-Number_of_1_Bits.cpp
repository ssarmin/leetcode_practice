//https://leetcode.com/problems/number-of-1-bits/description/
class Solution {
public:
    int hammingWeight(int n) {
        int num = 0;
        while(n){
            num += n&1;
            n = n >> 1;
        }
        return num;
    }
};
//Time complexity: O(logN)
