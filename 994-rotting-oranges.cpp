// https://leetcode.com/problems/rotting-oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int s=0; s<size; s++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0; i<4; i++){
                    int x = r + dx[i];
                    int y = c + dy[i];
                    if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                        flag = true;
                    }
                }
            }
            if(flag){
                count++;
            }
        }

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }

        return count;
    }
};
// [[1,2,1,1,2,1,1]]
// [[0,1]]
// [[1]]
// [[0]]
// [[2]]
// [[2,1,1],[1,1,0],[0,0,2]]
// [[2,1,1],[1,1,0],[0,1,1]]
// [[1,1,1],[1,1,0],[0,1,1]]
// [[2,1,1],[1,1,0],[0,0,1]]
// [[1,1,1],[1,1,0],[0,0,2]]
// [[2,1,1],[1,1,0],[0,0,2]]
// [[2,1,1],[1,1,0],[0,1,2],[0,0,1],[0,0,1],[0,0,1]]
// [[2,0,1],[0,0,0],[0,1,2]]
// [[2,2],[1,1],[0,0],[2,0]]
// [[2,1,1],[1,1,0],[0,1,2]]
