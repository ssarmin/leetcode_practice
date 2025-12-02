//https://leetcode.com/problems/regular-expression-matching
class Solution {
public:
    bool helper(int index_s, int index_p, string &s, string &p, unordered_map<int, unordered_map<int, bool>> &m){
        if(m.count(index_s) && m[index_s].count(index_p)){
            return m[index_s][index_p];
        }
        if(index_p == p.size())
            return m[index_s][index_p] = (index_s == s.size());

        bool curr_check = (index_s < s.size()) && ((s[index_s] == p[index_p]) || (p[index_p] == '.'));
        if(index_p + 1 < p.size() && p[index_p+1] == '*'){
            bool ans = helper(index_s, index_p+2, s, p, m);

            if(!ans && curr_check){
                ans = helper(index_s+1, index_p, s, p, m);
            }
            m[index_s][index_p] = ans;
            return ans;
        }
        if(curr_check){
            m[index_s][index_p] = helper(index_s+1, index_p+1, s, p, m);
        }else{
            m[index_s][index_p] = false;
        }
        return m[index_s][index_p];
    }
    bool isMatch(string s, string p) {
        unordered_map<int, unordered_map<int, bool>> m;
        return helper(0, 0, s, p, m);
    }
};
/*
"ab"
".*"
"aa"
"a*a"
"mississippi"
"mis*is*p*."
"aab"
"c*a*b"
"ab"
".*c"
"abc"
"a*abc"
"aab"
"c*aa*b"
*/
