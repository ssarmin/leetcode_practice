//https://leetcode.com/problems/edit-distance
class Solution {
public:
    int helper(int r, int c, string word1, string word2, unordered_map<int, unordered_map<int, int>> &m){
        if(r == word1.size()){
            return word2.size() - c;
        }
        if(c == word2.size()){
            return word1.size() - r;
        }
        if(m.count(r) && m[r].count(c)){
            return m[r][c];
        }
        if(word1[r] == word2[c]){
            m[r][c] = helper(r+1, c+1, word1, word2, m);
        }else{
            int res = helper(r+1, c, word1, word2, m);
            res = min(res, helper(r, c+1, word1, word2, m));
            res = min(res, helper(r+1, c+1, word1, word2, m));
            m[r][c] = res + 1;
        }
        return m[r][c];
    }
    int minDistance(string word1, string word2) {
        unordered_map<int, unordered_map<int, int>> m;
        return helper(0, 0, word1, word2, m);
    }
};

/*
"horse"
"ros"
"intention"
"execution"
""
""
"abc"
"defghi"
"leet"
"code"
"azertyqsdfghqwerty"
"azertyjklmqwerty"
"aaaaaaaaaaaaaaaaaaaaaa"
"aaaaaaaaaaaaaav"
"aaayuio"
"hjklaaa"
*/
