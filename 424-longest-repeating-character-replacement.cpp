//https://leetcode.com/problems/longest-repeating-character-replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int left = 0;
        int right = 0;
        int res = 0;
        while(left <= right && right < s.size()){
            m[s[right]]++;
            right++;
            int max_val = 0;
            for(auto a: m){
                max_val = max(max_val, a.second);
            }
            int window = right - left;
            int change = window - max_val;
            if(change <= k){
                res = max(res, window);
            }else{
                m[s[left]]--;
                left++;
            }
        }
        return res;
    }
};

// "IMNJJTRMJEGMSOLSCCQICIHLQIOGBJAEHQOCRAJQMBIBATGLJDTBNCPIFRDLRIJHRABBJGQAOLIKRLHDRIGERENNMJSDSSMESSTR"
// 2
// "ABCCABCCABA"
// 2
// "ABBB"
// 2
