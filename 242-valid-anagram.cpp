//https://leetcode.com/problems/valid-anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for(auto ch: s){
            m[ch]++;
        }
        for(auto ch: t){
            if(m.find(ch) == m.end() || m[ch] == 0){
                return false;
            }
            m[ch]--;
        }

        return true;
    }
};

// "aacc"
// "ccac"
// "aa"
// "bb"
// "ab"
// "ba"
