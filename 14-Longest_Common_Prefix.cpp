//https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
public:
    string get_common(string str1, string str2){
        string res = "";
        for(int i=0; i<str1.size() && i < str2.size(); i++){
            if(str1[i] == str2[i]){
                res += str1[i];
            }else
                break;
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        // sort(strs.begin(), strs.end());
        string res = strs[0];
        for(unsigned int i=1; i<strs.size(); i++){
            res = get_common(res, strs[i]);
            if(res.size() == 0)
                return "";
        }

        return res;
    }
};

// ["aca","cba"]
// ["rat", "a", "rattled"]
// ["a", "a", "b"]
