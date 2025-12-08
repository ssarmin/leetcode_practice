//https://leetcode.com/problems/shortest-bridge
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> update(vector<vector<int>> &grid, int r, int c){
        queue<pair<int, int>> res, q;
        q.push({r, c});
        grid[r][c] = -1;
        res.push({r, c});
        while(!q.empty()){
            auto [r, c] =  q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1){
                    q.push({x,y});
                    grid[x][y] = -1;
                    res.push({x,y});
                }
            }
        }
        return res;
    }
    int getShortPath(queue<pair<int, int>> &q, vector<vector<int>> &grid, vector<vector<int>> &dist){
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r, c] = q.front();
                q.pop();
                if(grid[r][c] == 1){
                    return res - 1;
                }
                if(dist[r][c] != INT_MAX)continue;
                dist[r][c] = res;
                for(int i=0; i<4; i++){
                    int x = r + dx[i];
                    int y = c + dy[i];
                    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && dist[x][y] == INT_MAX){
                        q.push({x,y});
                    }
                }
            }
            res++;
        }
        return res;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool flag = false;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] == 0)continue;
                q = update(grid, r, c);
                flag = true;
                break;
            }
            if(flag)
                break;
        }
        vector<vector<int>> dist(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        return getShortPath(q, grid, dist);
    }
};
/*
[[0,1,0,0,0],[0,1,0,1,1],[0,0,0,0,1],[0,0,0,0,0],[0,0,0,0,0]]
[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
*/
