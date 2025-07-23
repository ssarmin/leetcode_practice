//https://leetcode.com/problems/merge-strings-alternately
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int index = 0;
        while(index < word1.size() && index < word2.size()){
            res.push_back(word1[index]);
            res.push_back(word2[index]);
            index++;
        }
        while(index < word1.size()){
            res.push_back(word1[index]);
            index++;
        }
        while(index < word2.size()){
            res.push_back(word2[index]);
            index++;
        }
        return res;
    }
};
