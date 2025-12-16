//https://leetcode.com/problems/palindrome-permutation
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(auto ch: s){
            m[ch]++;
        }
        bool flag = true;
        for(auto a: m){
            if(a.second%2 == 1){
                if(flag){
                    flag = false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
/*
"carerac"
"code"
"a"
"aa"
"ab"
"abc"
"aabb"
"aabbc"
"aabbccdde"
"aaaaabbbbb"
"abcabcabc"
"zzzzzz"
"abababab"
"tactcoa"
"abcdefghijklmnopqrstuvwxyza"
*/
