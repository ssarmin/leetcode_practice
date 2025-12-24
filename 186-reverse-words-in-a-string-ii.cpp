//https://leetcode.com/problems/reverse-words-in-a-string-ii
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int left = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+left, s.begin()+i);
                left = i+1;
            }
        }
        reverse(s.begin()+left, s.end());
    }
};
/*
["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
["a"]
["h","e","l","l","o"]
["h","e","l","l","o"," ","w","o","r","l","d"]
["o","n","e"," ","t","w","o"," ","t","h","r","e","e"]
["L","e","e","t","C","o","d","e"]
["R","e","v","e","r","s","e"," ","w","o","r","d","s"]
["a","b","c"," ","d","e","f"," ","g","h","i"]
["1","2","3"," ","4","5","6"]
["M","i","x","e","d"," ","C","a","s","e"," ","W","o","r","d","s"]
["S","p","a","c","e","s"," ","i","n"," ","b","e","t","w","e","e","n"]
["A"," ","B"," ","C"]
*/
