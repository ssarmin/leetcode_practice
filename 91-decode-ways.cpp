//https://leetcode.com/problems/decode-ways
class Solution {
public:
    int helper(string s, int index, unordered_map<int, int> &m){
        if(index > s.size())
            return 0;
        if(m.count(index))
            return m[index];
        if(index == s.size())
            return 1;
        if(s[index] == '0')
            return 0;
        int val = helper(s, index+1, m);
        if(index+1 < s.size() && (s[index] <= '1' || (s[index] <= '2' &&  s[index+1] <= '6'))){
            val += helper(s, index+2, m);
        }
        m[index] = val;
        return val;
    }
    int numDecodings(string s) {
        unordered_map<int, int> m;
        return helper(s, 0, m);
    }
};

/*
"11"
"10"
"2026"
"1010"
"12120"
"160"
"2611055971756562"
"111111111111111111111111111111111111111111111"
*/
