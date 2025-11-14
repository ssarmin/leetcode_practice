//https://leetcode.com/problems/interleaving-string
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        if(s1.size() == 0 && s2.size() == 0)
            return s3.size() == 0;
        if(s1.size() == 0)
            return s2 == s3;
        if(s2.size() == 0)
            return s1 == s3;
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        set<tuple<int, int, int>> s;
        while(!q.empty()){
            auto [index_1, index_2, index_3] = q.front();
            q.pop();
            if(s.count({index_1, index_2, index_3}))
                continue;
            s.insert({index_1, index_2, index_3});
            if(index_3 == s3.size())
                return true;
            if(index_2 < s2.size() && s3[index_3] == s2[index_2]){
                q.push({index_1, index_2+1, index_3+1});
            }
            if(index_1 < s1.size() && s3[index_3] == s1[index_1]){
                q.push({index_1+1, index_2, index_3+1});
            }
        }
        return false;
    }
};
/*
"aabc"
"abad"
"aabadabc"
"aabcc"
"dbbca"
"aadbbbaccc"
"abababababababababababababababababababababababababababababababababababababababababababababababababbb"
"babababababababababababababababababababababababababababababababababababababababababababababababaaaba"
"abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
"abc"
"def"
"abcdefg"
"aab"
"axy"
"aaxaby"
"aabc"
"abad"
"aabadabc"
"a"
"b"
"a"
"ab"
"bc"
"babc"
*/
