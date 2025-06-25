// https://leetcode.com/problems/length-of-last-word
class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        reverse(s.begin(), s.end());
        istringstream ss(s);
        while(ss >> word){
            return word.size();
        }
        return 0;
    }
};
