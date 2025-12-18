//https://leetcode.com/problems/restore-ip-addresses
class Solution {
public:
    void update(int part, string s, int index, string v, vector<string> &res){
        if(part > 3)
            return;
        if((4 - part)*3 < (s.size() - index) || (4 - part) > (s.size() - index))
            return;
        if(part == 3){
            string str = s.substr(index);
            int num = stoi(str);
            if(str == to_string(num) && num <= 255){
                v += ".";
                v += str;
                res.push_back(v);
            }
            return;
        }
        for(int i=0; i<3 && (i+index) < s.size(); i++){
            string str = s.substr(index, i+1);
            int num = stoi(str);
            if(str == to_string(num) && num <= 255){
                if(v == ""){
                    update(part+1, s, index+i+1, str, res);
                }else{
                    update(part+1, s, index+i+1, v + "." + str, res);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return {};
        vector<string> res;
        update(0, s, 0, "", res);
        return res;
    }
};
//"010010"
// "2552551113534453"
// "25525511135"
