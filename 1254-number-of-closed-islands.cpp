//https://leetcode.com/problems/number-of-closed-islands
class Solution {
public:
    bool helper(vector<vector<bool>> &visit, int r, int c, const vector<vector<int>> &grid){
        bool edge = false;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        q.push({r,c});
        visit[r][c] = true;
        if(r == 0 || c == 0 || r == grid.size()-1 || c == grid[0].size()-1){
            edge = true;
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = dx[i] + r;
                int y = dy[i] + c;
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !visit[x][y] && grid[x][y] == 0){
                    if(x == 0 || y == 0 || x == grid.size()-1 || y == grid[0].size()-1){
                        edge = true;
                    }
                    visit[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return !edge;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 0 && !visit[r][c]){
                    if(helper(visit, r, c, grid)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
/*
[[0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,1,0],[1,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,0,0,1,0]]
[[1,0,1,1,1,1,0,0,1,0],[1,0,1,1,0,0,0,1,1,1],[0,1,1,0,0,0,1,0,0,0],[1,0,1,1,0,1,0,0,1,0],[0,1,1,1,0,1,0,1,0,0],[1,0,0,1,0,0,1,0,0,0],[1,0,1,1,1,0,0,1,1,0],[1,1,0,1,1,0,1,0,1,1],[0,0,1,1,1,0,1,0,1,1],[1,0,0,1,1,1,1,0,1,1]] 
[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
[[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
[[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]
[[0,0,1,1,0,1,0,0,1,0],[1,1,0,1,1,0,1,1,1,0],[1,0,1,1,1,0,0,1,1,0],[0,1,1,0,0,0,0,1,0,1],[0,0,0,0,0,0,1,1,1,0],[0,1,0,1,0,1,0,1,1,1],[1,0,1,0,1,1,0,0,0,1],[1,1,1,1,1,1,0,0,0,0],[1,1,1,0,0,1,0,1,0,1],[1,1,1,0,1,1,0,1,1,0]] 
[[0,0,1,0,0],[0,1,0,1,0]]
[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,0,1,1,1,1,1,0]]
*/
