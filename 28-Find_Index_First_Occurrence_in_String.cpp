//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        
        return haystack.find(needle);
    }
};
