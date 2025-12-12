https://leetcode.com/problems/shortest-distance-from-all-buildings
class Solution {
public:
    void update(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dist_temp, vector<vector<int>> &accessible){
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        q.push({r,c});
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                auto [r, c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int x = r + dx[i];
                    int y = c + dy[i];
                    if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0 && !visit[x][y]){
                        if(dist_temp[x][y] == INT_MAX)
                            dist_temp[x][y] = count;
                        else
                            dist_temp[x][y] += count;

                        accessible[x][y]++;
                        q.push({x,y});
                        visit[x][y] = true;
                    }
                }
            }
        }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> houses;
        int row = grid.size();
        int col = grid[0].size();
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 1){
                    houses.push_back({r, c});
                }
            }
        }
        if(houses.size() == 0)
            return 0;
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        vector<vector<int>> accessible(row, vector<int>(col, 0));
        for(auto h: houses){
            update(h.first, h.second, grid, dist, accessible);
        }
        int res = INT_MAX;
        for(int i=0; i<dist.size(); i++){
            for(int j=0; j<dist[0].size(); j++){
                if(accessible[i][j] == houses.size())
                    res = min(res, dist[i][j]);
            }
        }

        return res == INT_MAX? -1: res;
    }
};
/*
[[1,1,1,1,1,0],[0,0,0,0,0,1],[0,1,1,0,0,1],[1,0,0,1,0,1],[1,0,1,0,0,1],[1,0,0,0,0,1],[0,1,1,1,1,0]]
[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
[[1,0]]
[[1,2,0]]
[[0,2,1],[1,0,2],[0,1,0]]
[[1,1,1,1,1,1,1,0],[0,0,0,0,0,0,0,1],[0,1,1,1,1,0,0,1],[1,0,0,0,0,1,0,1],[1,0,0,1,0,1,0,1],[1,0,1,0,0,1,0,1],[1,0,0,1,1,0,0,1], [1,0,0,0,0,0,0,1],[0,1,1,1,1,1,1,0]]
[[1, 1],[1, 0]]
[[1,1],[0,1]]
*/
