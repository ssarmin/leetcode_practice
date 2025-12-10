//https://leetcode.com/problems/shortest-path-to-get-all-keys
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n_keys = 0;
        pair<int, int> pos;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '@'){
                    pos = {i, j};
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    n_keys++;
                }
            }
        }
        int goal_mask = (1 << n_keys) - 1;
        vector<vector<vector<bool>>> visit(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(1 << n_keys, false)));

        queue<tuple<int, int, int, int>> q;// pos_x, pos_y, mask, move
        q.push({pos.first, pos.second, 0, 0});
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while(!q.empty()){
            auto [r, c, mask, move] = q.front();
            q.pop();
            if(mask == goal_mask){
                return move;
            }
            if(visit[r][c][mask])
                continue;
            visit[r][c][mask] = true;
            for(int i=0; i<4; i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size()){
                    if(grid[x][y] == '#')
                        continue;
                    if(grid[x][y] >= 'a' && grid[x][y] <= 'f'){
                        int index = grid[x][y] - 'a';
                        int new_mask = mask | (1 << index);
                        if(visit[x][y][new_mask])continue;
                        q.push({x, y, new_mask, move+1});
                    }else if(grid[x][y] >= 'A' && grid[x][y] <= 'F'){
                        int index = grid[x][y] - 'A';
                        int bit = mask & (1 << index);
                        if(bit == 0)continue;
                        if(visit[x][y][mask])continue;
                        q.push({x, y, mask, move+1});
                    }else{
                        if(visit[x][y][mask])continue;
                        q.push({x, y, mask, move+1});
                    }
                }
            }
        }
        return -1;
    }
};
/*
["@...a",".###A","b.BCc"]
["Dd#b@",".fE.e","##.B.","#.cA.","aF.#C"]
[".##..##..B","##...#...#","..##..#...",".#..#b...#","#.##.a.###",".#....#...",".##..#.#..",".....###@.","..........",".........A"]
["###.D.B.F.","..#b......","##....#..#","....@..#..","#d.AE.##c#",".....##.f.","#........C","..a#.#....","#....#e..#","........##"]
["...#.","a..@.","#..#.","b.#B.",".##.A"]
["@fedcbBCDEFaA"]
["###@##","cB.bCa","#####A"]
["...#.","a..@.","#..#.","b.#B.",".##.A"]
[".@aA"]
*/
