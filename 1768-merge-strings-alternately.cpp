//https://leetcode.com/problems/merge-strings-alternately
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string res = "";
        int index = 0;
        int l1 = word1.size();
        int l2 = word2.size();
        res.resize(l1 + l2);
        while(i < l1 || i < l2){
            if(i < l1) res[index++] += word1[i];
            if(i < l2) res[index++] += word2[i];
            i++;
        }
        return res;
    }
};
