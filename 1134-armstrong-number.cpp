//https://leetcode.com/problems/armstrong-number
class Solution {
public:
    bool isArmstrong(int n) {
        string str = to_string(n);
        long long val = 0;
        int k = (int)str.size();
        for(auto ch: str){
            val += pow((ch - '0'), k);
        }
        return val == n;
    }
};
/*
100000000
99999999
*/
