//https://leetcode.com/problems/n-queens
class Solution {
public:
    bool check(int r, int c, vector<string> &v){
        for(int i=r-1; i>=0; i--){
            if(v[i][c] == 'Q')
                return false;
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(v[i][j] == 'Q')
                return false;
        }
        for(int i=r-1, j=c+1; i>=0 && j<v.size(); i--, j++){
            if(v[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void helper(int r, vector<string> &v, vector<vector<string>> &res){
        if(r == v.size()){
            res.push_back(v);
            return;
        }
        for(int c=0; c<v.size(); c++){
            if(check(r, c, v)){
                v[r][c] = 'Q';
                helper(r+1, v, res);
                v[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        int r = 0;
        vector<vector<string>> res;
        helper(r, v, res);
        return res;
    }
};
