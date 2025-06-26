//https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index1 = 0;
        int index2 = 0;

        while(index1 < s.size() && index2 < t.size()){
            if(s[index1] == t[index2]){
                index1++;
                index2++;
            }else{
                index2++;
            }
        }

        return (index1 == s.size());
    }
};
