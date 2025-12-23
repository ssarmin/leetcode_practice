//https://www.geeksforgeeks.org/dsa/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
//https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int left = 0;
        unordered_map<char, int> m;
        int max_len = 0;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            while(m.size() > k){
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
/*
"eceba"
2
"aa"
1
"a"
0
"abc"
1
"abc"
2
"abc"
3
"aaaaabbbbb"
1
"aaaaabbbbb"
2
"abababab"
2
"abababab"
1
"abcabcabc"
2
"abcabcabc"
3
"aaabbbccc"
2
"aaabbbccc"
1
"abcdefghijklmnopqrstuvwxyz"
5
"abcdefghijklmnopqrstuvwxyz"
26
"aaaaaaaaaaaaaaaaaaaa"
50
"abaccc"
2
*/
