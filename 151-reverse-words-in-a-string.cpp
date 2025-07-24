//https://leetcode.com/problems/reverse-words-in-a-string
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        string res = "";
        while(ss >> word){
            cout << word;
            res = word + " " + res;
        }
        res.pop_back();
        return res;
    }
};
