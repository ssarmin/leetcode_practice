//https://leetcode.com/problems/consecutive-characters/
class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0)
            return 0;
        int res = 1;
        char prev = s[0];
        int count = 1;
        for(int i=1; i<s.size(); i++){
            if(prev == s[i]){
                count++;
            }else{
                res = max(res, count);
                count = 1;
                prev = s[i];
            }
        }
        res = max(res, count);
        return res;
    }
};

/*
"letcode"
"leetcode"
"llllleetcode"
"leetcodeeeee"
"e"
"eee"
"ebe"
"abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghiiabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"
*/
