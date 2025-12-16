//https://leetcode.com/problems/one-edit-distance
class Solution {
public:
    bool flag = true;
    bool isOneEditDistance(string s, string t) {
        if(s == t || abs((int)s.size() - (int)t.size()) > 1){
            return false;
        }
        if(s.size() > t.size()){
            return isOneEditDistance(t, s);
        }
        if(s.size() == t.size()){
            for(int i=0; i<s.size(); i++){
                if(s[i] != t[i]){
                    if(flag)
                        flag = false;
                    else
                        return false;
                }
            }
        }else{
            for(int i=0; i<s.size(); i++){
                if(s[i] != t[i]){
                    if(flag){
                        flag = false;
                        string insert_s = s.substr(i);
                        string delete_s = insert_s;
                        string insert_t = t.substr(i);
                        insert_s = insert_t[0] + insert_s;
                        string delete_t = t.substr(i+1);
                        return (insert_s == insert_t) || (delete_t == delete_s);
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
/*
"teacher"
"tache"
"ab"
"cab"
"ba"
"a"
"aca"
"caca"
"a"
""
"cb"
"ab"
"a"
"A"
"a"
"b"
"ab"
"ab"
"abc"
"ab"
"abc"
"adc"
""
"a"
"a"
""
"abcd"
"abdc"
"kitten"
"sitten"
*/
