//https://leetcode.com/contest/biweekly-contest-161/problems/count-islands-with-total-value-divisible-by-k/
class Solution {
public:
    long long bfs(int r, int c, vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        q.push({r, c});
        
        long long sum = 0;
        sum += grid[r][c];
        grid[r][c] = 0;
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int x = dx[i] + r;
                int y = dy[i] + c;
                if(x >= 0 && x <grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != 0){
                    q.push({x, y});
                    sum += grid[x][y];
                    grid[x][y] = 0;
                }
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] != 0){
                    long long val = bfs(r, c, grid);
                    if(val % k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
