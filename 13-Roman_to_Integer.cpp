//https://leetcode.com/problems/roman-to-integer/description/
class Solution {
public:
    void update_map(unordered_map<char, int> &m){
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
    }

    int romanToInt(string s) {
        unordered_map<char, int> m;
        update_map(m);
        int num = 0;
        int prev = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(prev > m[s[i]]){
                num -= m[s[i]];
            }else{
                num += m[s[i]];
            }
            prev = m[s[i]];
        }

        return num;
    }
};
/*
Extra testcases:
"XLIX"
"XCIX"
"MCMXCVI"
"MMMDCCCLXXXVIII"
*/
