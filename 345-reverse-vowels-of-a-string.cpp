//https://leetcode.com/problems/reverse-vowels-of-a-string
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> _set{'a', 'e', 'i', 'o','u','A','E','I','O','U'};
        vector<int> v;
        for(auto ch: s){
            if(_set.count(ch)){
                v.push_back(ch);
            }
        }
        reverse(v.begin(), v.end());
        int index = 0;
        for(int i=0; i<s.size(); i++){
            if(_set.count(s[i])){
                s[i] = v[index]; 
                index++;
            }
        }
        return s;
    }
};
