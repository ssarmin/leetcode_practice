//https://leetcode.com/problems/brace-expansion
class Solution {
public:
    void helper(vector<string> &res, const vector<vector<string>> &v){
        queue<pair<string, int>> q;
        q.push({"", 0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [str, index] = q.front();
                q.pop();
                if(index == v.size()){
                    res.push_back(str);
                    continue;
                }
                for(auto s: v[index]){
                    q.push({str+s, index+1});
                }
            }
        }
    }
    vector<string> expand(string s) {
        vector<vector<string>> v;
        bool new_v = true;
        string str = "";
        for(auto ch: s){
            if(ch == ','){
                if(new_v){
                    v.push_back({str});
                }else{
                    v.back().push_back(str);
                }
                str = "";
                new_v = false;
                continue;
            }
            if(ch == '{' || ch == '}'){
                if(new_v){
                    v.push_back({str});
                }else{
                    v.back().push_back(str);
                }
                new_v = true;
                str = "";
                continue;
            }
            str += ch;
        }
        if(new_v){
            v.push_back({str});
        }else{
            v.back().push_back(str);
        }
        vector<string> res;
        helper(res, v);
        sort(res.begin(), res.end());
        return res;
    }
};
//"{a,b}{z,x,y}"
