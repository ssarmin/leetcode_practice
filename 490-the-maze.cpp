//https://leetcode.com/problems/the-maze
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};//up, down, right, left
        queue<tuple<int, int, int>> q;//x,y,index
        q.push({start[0], start[1], -1});
        vector<vector<vector<int>>> visit(maze.size(), vector<vector<int>>(maze[0].size(), vector<int>(4, false)));
        while(!q.empty()){
            auto [r, c, index] = q.front();
            q.pop();
            if(r == destination[0] && c == destination[1])
                return true;
            for(int i=0; i<4; i++){
                if(index == 0 && i == 1)
                    continue;
                if(index == 1 && i == 0)
                    continue;
                if(index == 2 && i == 3)
                    continue;
                if(index == 3 && i == 2)
                    continue;
                int x = r + dx[i];
                int y = c + dy[i];
                while(x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0){
                    x = x + dx[i];
                    y = y + dy[i];
                }
                x = x - dx[i];
                y = y - dy[i];
                if(visit[x][y][i])continue;
                q.push({x,y,i});
                visit[x][y][i] = true;
            }
        }
        return false;
    }
};

/*
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[1,2]
[[0,0,0],[0,0,0],[0,0,0]]
[0,0]
[1,2]
[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[3,2]
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,0],[0,0,0,0,0]]
[0,4]
[1,0]
*/
