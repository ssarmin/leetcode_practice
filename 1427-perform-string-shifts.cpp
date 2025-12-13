https://leetcode.com/problems/perform-string-shifts
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total = 0;
        for(auto s: shift){
            if(s[0] == 0){
                total -= s[1];
            }else{
                total += s[1];
            }
        }
        if(total == 0)
            return s;
        else if(total > 0){//right shift
            total = total%s.size();
            string first_part = s.substr(0, s.size()-total);
            string last_part = s.substr(first_part.size());
            return last_part + first_part;
        }else{
            total = abs(total)%s.size();
            string first_part = s.substr(0, total);
            string last_part = s.substr(total);
            return last_part + first_part;
        }
    }
};
/*
"mecsk"
[[1,15],[0,10],[0,13],[1,24],[1,31]]
"joiazl"
[[1,1],[0,1],[1,3],[1,0],[0,3]]
"abc"
[[0,4]]
"wpdhhcj"
[[0,7],[1,7],[1,0],[1,3],[0,3],[0,6],[1,2]]
*/
