//https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k > s.size())
            return 0;
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_set<char> _set;
        for(; right < s.size(); right++){
            while(left < right && _set.count(s[right])){
                _set.erase(s[left]);
                left++;
            }
            _set.insert(s[right]);
            while((right - left + 1) >= k){
                if(_set.size() == k){
                    count++;
                }
                _set.erase(s[left]);
                left++;
            }
        }
        return count;
    }
};
