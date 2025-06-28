// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        for(int i = 0; i<=haystack.size()-needle.size(); i++){
            int index = 0;
            while(i+index < haystack.size() && index < needle.size() && haystack[i+index] == needle[index]){
                index++;
            }
            if(index == needle.size())
                return i;
        }

        return -1;
    }
};

// "abb"
// "abaaa"
// "adcadcaddcadde"
// "adcadde"
// "mississippi"
// "a"
// "ababcaababcaabc"
// "ababcaabc"
// "aaaaa"
// "bba"
// "mississippi"
// "issip"
