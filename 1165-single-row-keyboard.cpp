//https://leetcode.com/problems/single-row-keyboard
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        int index = 0;
        for(auto ch: keyboard){
            m[ch] = index;
            index++;
        }
        index = 0;
        int res = 0;
        for(auto ch: word){
            res += abs(index - m[ch]);
            index = m[ch];
        }
        return res;
    }
};
