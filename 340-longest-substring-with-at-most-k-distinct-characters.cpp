//https://www.geeksforgeeks.org/dsa/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
//https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char, int> m;
        int left = 0;
        int res = INT_MIN;
        for(int right = 0; right < s.size(); right++){
            m[s[right]]++;
            while(left < right && m.size() > k){
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }
            if(m.size() == k){
                res = max(res, right - left + 1);
            }
        }
        return res == INT_MIN? -1: res;
    }
};
