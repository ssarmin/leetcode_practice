// https://leetcode.com/problems/rotting-oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int good = 0;
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c] == 1)
                    good++;
                else if(grid[r][c] == 2)
                    q.push({r, c});
            }
        }

        if(good == 0)
            return 0;
        if(q.size() == 0)
            return -1;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            while(size--){
                auto [r, c] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int x = dx[i] + r;
                    int y = dy[i] + c;

                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1){
                        good--;
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

        return good == 0? count: -1;
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
