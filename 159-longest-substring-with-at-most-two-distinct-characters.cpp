//https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0;
        unordered_map<char, int> m;
        int max_len = 0;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            while(m.size() > 2){
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
