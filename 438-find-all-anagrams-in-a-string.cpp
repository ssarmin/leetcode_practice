//https://leetcode.com/problems/find-all-anagrams-in-a-string
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> p_map;
        for(auto a: p){
            p_map[a]++;
        }
        int left = 0;
        vector<int> res;
        unordered_map<char, int> s_map;
        int count = 0;
        for(int right=0; right<s.size(); right++){
            char ch = s[right];
            if(p_map.count(ch)){
                s_map[ch]++;
                if(s_map[ch] == p_map[ch]){
                    count++;
                }
                while(s_map[ch] > p_map[ch]){
                    s_map[s[left]]--;
                    if(s_map[s[left]]+1 == p_map[s[left]]){
                        count--;
                    }
                    left++;
                }
                if(p_map.size() == count){
                    res.push_back(left);
                    s_map[s[left]]--;
                    if(s_map[s[left]]+1 == p_map[s[left]]){
                        count--;
                    }
                    left++;
                }
            }else{
                count = 0;
                left = right + 1;
                s_map.clear();
            }
        }
        return res;
    }
};

// "cbbbaa"
// "cccbba"
// "abacbabc"
// "abc"
// https://leetcode.com/submissions/detail/633226267/testcase/
