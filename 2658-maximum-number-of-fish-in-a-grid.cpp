//https://leetcode.com/problems/maximum-number-of-fish-in-a-grid
class Solution {
public:
    void bfs(vector<vector<int>> &grid, int r, int c, int &maxVal){
        queue<pair<int, int>> q;
        q.push({r, c});
        int val = grid[r][c];
        grid[r][c] = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int x = dx[i] + r;
                int y = dy[i] + c;
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] > 0){
                    q.push({x, y});
                    val += grid[x][y];
                    grid[x][y] = 0;
                }
            }
        }
        maxVal = max(maxVal, val);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxVal = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] > 0){
                    bfs(grid, r, c, maxVal);
                }
            }
        }
        return maxVal;
    }
};

// [[0]]
// [[4]]
// [[0, 0]]
// [[0, 6, 0, 9]]
// [[4, 5, 5], [0, 10, 0]]
// [[3], [4], [0], [4], [8], [9], [0]]
// [[10, 0, 2, 10, 10, 6], [2, 2, 0, 0, 1, 4], [6, 5, 0, 6, 0, 6], [1, 6, 0, 1, 4, 6], [4, 0, 0, 0, 10, 5]]
// [[9, 1, 1, 6, 9, 7, 9, 1, 10, 8], [2, 5, 6, 1, 3, 5, 9, 7, 10, 10], [9, 2, 2, 9, 5, 0, 8, 2, 10, 0], [9, 2, 6, 3, 10, 2, 0, 9, 0, 7], [10, 3, 7, 10, 5, 3, 5, 9, 3, 9], [10, 2, 9, 7, 8, 5, 10, 8, 5, 4], [6, 3, 5, 5, 7, 2, 8, 8, 1, 0], [5, 7, 3, 8, 6, 9, 9, 8, 10, 2]]
