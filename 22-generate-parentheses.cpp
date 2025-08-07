//https://leetcode.com/problems/generate-parentheses
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<tuple<int, int, string>> s;
        s.push({0, 0, ""});

        while(!s.empty()){
            auto [open, close, str] = s.top();
            s.pop();
            if(open == n && close == n){
                res.push_back(str);
                continue;
            }
            if(open < n){
                s.push({open+1, close, str+"("});
            }
            if(open > close){
                s.push({open, close+1, str+")"});
            }
        }

        return res;
    }
};

//8
