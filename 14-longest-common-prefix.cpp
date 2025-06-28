//https://leetcode.com/problems/longest-common-prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = strs[0].size();
        for(int i=1; i<strs.size(); i++){
            minLen = min(minLen, (int)strs[i].size());
        }
        string str = "";
        for(int l=0; l<minLen; l++){
            char ch = strs[0][l];
            for(int i=1; i<strs.size(); i++){
                if(ch != strs[i][l])
                    return str;
            }
            str += ch;
        }

        return str;
    }
};

// ["flower","flower","flower","flower"]
// ["aca","cba"]
// ["rat", "a", "rattled"]
// ["a", "a", "b"]
