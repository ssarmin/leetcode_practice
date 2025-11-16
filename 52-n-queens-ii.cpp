//https://leetcode.com/problems/n-queens-ii
class Solution {
public:
    bool check(int r, int c, vector<vector<bool>> &v){
        for(int i=r-1; i>=0; i--){
            if(v[i][c])
                return false;
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
            if(v[i][j])
                return false;
        }
        for(int i=r-1, j=c+1; i>=0 && j<v.size(); i--, j++){
            if(v[i][j])
                return false;
        }
        return true;
    }
    void helper(int r, vector<vector<bool>> &v, int &res){
        if(r == v.size()){
            res++;
            return;
        }
        for(int c=0; c<v.size(); c++){
            if(check(r, c, v)){
                v[r][c] = true;
                helper(r+1, v, res);
                v[r][c] = false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>> v(n, vector<bool>(n, false));
        int r = 0;
        int res = 0;
        helper(r, v, res);
        return res;
    }
};
