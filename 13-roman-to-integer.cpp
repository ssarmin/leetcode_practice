//https://leetcode.com/problems/roman-to-integer
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int prev = m[s[0]];
        int val = prev;
        for(int i=1; i<s.size(); i++){
            if(prev < m[s[i]]){
                val = val - prev - prev;
            }
            val += m[s[i]];
            prev = m[s[i]];
        }

        return val;
    }
};

/*
Extra testcases:
"XLIX"
"XCIX"
"MCMXCVI"
"MCDLXXVI"
"MCMXCIV"
"MMMDCCCLXXXVIII"
*/
