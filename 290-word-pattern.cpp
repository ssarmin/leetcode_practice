//https://leetcode.com/problems/word-pattern
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        unordered_map<string, char> m;
        unordered_map<char, string> m_rev;
        int index = 0;
        while(ss >> word){
            if(index == pattern.size())
                return false;
            
            if(m.find(word) != m.end()){
                if(m[word] != pattern[index])
                    return false;
            }
            if(m_rev.find(pattern[index]) != m_rev.end()){
                if(word != m_rev[pattern[index]])
                    return false;
            }
            m[word] = pattern[index];
            m_rev[pattern[index]] = word;

            index++;
        }
        return index == pattern.size();
    }
};

/*
"jquery"
"jquery"
"dog cat cat dog"
"a"
*/
