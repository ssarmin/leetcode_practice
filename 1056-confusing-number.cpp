//https://leetcode.com/problems/confusing-number
class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> m;
        m[0] = 0;
        m[1] = 1;
        m[6] = 9;
        m[8] = 8;
        m[9] = 6;

        string str = to_string(n);
        reverse(str.begin(), str.end());
        int val = 0;
        for(auto ch: str){
            int digit = ch - '0';
            if(!m.count(digit))
                return false;
            val = val*10 + m[digit];
        }
        if(n != val)
            return true;
        return false;
    }
};
/*
619
25
916
906
8101
81010
88001101
80
*/
