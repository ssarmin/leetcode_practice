//https://leetcode.com/problems/shortest-path-in-binary-matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0] == 1 || grid[row-1][col-1] == 1)
            return -1;
        
        int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

        vector<vector<int>> res(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        res[0][0] = 1;
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 0 && res[x][y] > res[r][c] + 1){
                    res[x][y] = res[r][c] + 1;
                    q.push({x,y});
                }
            }
        }
        return res[row-1][col-1] == INT_MAX? -1: res[row-1][col-1];
    }
};
/*
[[0,0,1,0,0,1,0,1,0],[0,0,0,0,0,0,0,0,0],[0,1,1,0,1,1,1,1,1],[0,0,0,1,0,0,0,0,0],[1,1,0,0,0,1,0,0,0],[1,0,1,0,0,1,0,0,1],[1,1,1,1,0,0,1,0,0],[1,0,0,1,0,0,1,1,1],[0,0,0,0,0,0,0,0,0]]
[[0,0,0,0,1,1,1,1,0],[0,1,1,0,0,0,0,1,0],[0,0,1,0,0,0,0,0,0],[1,1,0,0,1,0,0,1,1],[0,0,1,1,1,0,1,0,1],[0,1,0,1,0,0,0,0,0],[0,0,0,1,0,1,0,0,0],[0,1,0,1,1,0,0,0,0],[0,0,0,0,0,1,0,1,0]]
[[0,1,0,1],[1,0,1,0],[1,1,1,0],[1,0,0,0]]
*/
