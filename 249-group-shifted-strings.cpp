//https://leetcode.com/problems/group-shifted-strings
class Solution {
public:
    void update(unordered_map<string, int> &m, string str, vector<string> &v){
        for(int i=1; i<26; i++){
            string temp = str;
            for(int index=0; index<str.size(); index++){
                str[index] = 'a' + (str[index] - 'a' + i) % 26;
            }
            if(m.count(str)){
                for(int i=0; i<m[str]; i++){
                    v.push_back(str);
                }
                m.erase(str);
            }
            str = temp;
        }
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> m;
        for(auto str: strings){
            m[str]++;
        }
        vector<vector<string>> res;
        for(auto str: strings){
            if(!m.count(str))continue;
            vector<string> v;
            for(int i=0; i<m[str]; i++){
                v.push_back(str);
            }
            m.erase(str);
            update(m, str, v);
            res.push_back(v);
        }
        return res;
    }
};
/*
["abc","bcd","acef","xyz","az","ba","a","z"]
["cba","la"]
["a","a"]
*/

