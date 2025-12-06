//https://leetcode.com/problems/number-of-enclaves
class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({r,c});
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        bool flag = true;
        if(r == 0 || c == 0 || r == grid.size()-1 || c == grid[0].size()-1)
            flag = false;
        int count = 0;
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            count++;
            for(int i=0; i<4; i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                    grid[x][y] = -1;
                    if(x == 0 || y == 0 || x == grid.size()-1 || y == grid[0].size()-1){
                        flag = false;
                    }
                    q.push({x,y});
                }
            }
        }
        return flag? count:  0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 1){
                    grid[r][c] = -1;
                    count += helper(r, c, grid);
                }
            }
        }
        return count;
    }
};
/*
[[0,0,0,1,1,1,0,1,0,0], [1,1,0,0,0,1,0,1,1,1], [0,0,0,1,1,1,0,1,0,0], [0,1,1,0,0,0,1,0,1,0], [0,1,1,1,1,1,0,0,1,0], [0,0,1,0,1,1,1,1,0,1], [0,1,1,0,0,0,1,1,1,1], [0,0,1,0,0,1,0,1,0,1], [1,0,1,0,1,1,0,0,0,0], [0,0,0,0,1,1,0,0,0,1]]
[[0,0,0,1,1,1,0,1,0,0],[1,1,0,0,0,1,0,1,1,1],[0,0,0,1,1,1,0,1,0,0],[0,1,1,0,0,0,1,0,1,0],[0,1,1,1,1,1,0,0,1,0],[0,0,1,0,1,1,1,1,0,1],[0,1,1,0,0,0,1,1,1,1],[0,0,1,0,0,1,0,1,0,1],[1,0,1,0,1,1,0,0,0,0],[0,0,0,0,1,1,0,0,0,1]]
*/
