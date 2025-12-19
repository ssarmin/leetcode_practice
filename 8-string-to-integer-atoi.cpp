//https://leetcode.com/problems/string-to-integer-atoi
class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        bool neg = false;
        int index = 0;
        for(; index < s.size(); index++){
            if(s[index] != ' '){
                break;
            }
        }
        if(s[index] == '-'){
            neg = true;
            index++;
            long num = 0;
            for(; index < s.size(); index++){
                if(isdigit(s[index])){
                    num = num*10 - (s[index] - '0');
                }else{
                    break;
                }
                if(num < INT_MIN){
                    return INT_MIN;
                }
            }
            return (int)num;
        }else{
            if(s[index] == '+'){
                index++;
            }
            long num = 0;
            for(; index < s.size(); index++){
                if(isdigit(s[index])){
                    num = num*10 + (s[index] - '0');
                }else{
                    break;
                }
                if(num > INT_MAX){
                    return INT_MAX;
                }
            }
            return (int)num;
        }
    }
};
/*
"+1"
"21474836460"
"2147483646"
"18446744073709551617"
"words and 987"
"00000-42a1234"
"   +0 123"
"00000-42a1234"
"-91283472332"
"+-2"
" -115579378e25"
"0-1"
"-+-+-3"
" + 0 123"
"   +0 123"
" +004500"
"2147483648"
"   -42abc"
" -115579378e25"
"-91283472332"
"1+111"
" "
"9223372036854775808"
".1"
"010"
*/
