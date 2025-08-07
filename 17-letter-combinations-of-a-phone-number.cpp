//https://leetcode.com/problems/letter-combinations-of-a-phone-number
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> v;
        for(auto ch: digits){
            v.push_back(m[ch]);
        }
        vector<string> res = {""};
        for(int i=0; i<v.size(); i++){
            vector<string> temp = res;
            res = {};
            for(int j=0; j<v[i].size(); j++){
                for(auto s: temp){
                    s += v[i][j];
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

//"2357"
