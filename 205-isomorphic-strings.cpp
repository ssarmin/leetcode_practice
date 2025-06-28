//https://leetcode.com/problems/isomorphic-strings
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        if(s == t)
            return true;
        int index = 0;
        unordered_map<char, char> m;
        unordered_map<char, char> m_rev;
        while(index < t.size()){
            if(m.find(s[index]) == m.end() && m_rev.find(t[index]) == m_rev.end()){
                m[s[index]] = t[index];
                m_rev[t[index]] = s[index];
            }else if(m.find(s[index]) == m.end() && m_rev.find(t[index]) != m_rev.end()){
                return false;
            }else if(m.find(s[index]) != m.end() && m_rev.find(t[index]) == m_rev.end()){
                return false;
            }else{
                if(m[s[index]] != t[index] || m_rev[t[index]] != s[index])
                    return false;
            }
            index++;
        }
        return true;
    }
};

// "badc"
// "baba"
