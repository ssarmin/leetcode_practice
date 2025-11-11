//https://leetcode.com/problems/greatest-common-divisor-of-strings
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size())
            return gcdOfStrings(str2, str1);
        int len = str2.size();
        while(len >= 1){
            if(str2.size()%len == 0 && str1.size()%len == 0){
                string res = str2.substr(0, len);
                string temp1 = "";
                string temp2 = "";
                while(temp2.size() < str2.size()){
                    temp2 += res;
                }
                if(temp2 == str2){
                    while(temp1.size() < str1.size()){
                        temp1 += res;
                    }
                    if(temp1 == str1)
                        return res;
                }
            }
            len--;
        }
        return "";
    }
};

// "TAUXXTAUXXTAUXXTAUXXTAUXX"
// "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
// "ABCDEF"
// "ABC"
// "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
// "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
// "A"
// "AA"
