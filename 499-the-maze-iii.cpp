//https://leetcode.com/problems/the-maze-iii
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};//right, left, down, up
        priority_queue<tuple<int, int, int,int,string>, vector<tuple<int, int, int,int,string>>, greater<tuple<int, int, int,int,string>>> q;//move,x,y,index,path
        q.push({0, ball[0], ball[1], -1, ""});
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        vector<vector<string>> path(maze.size(), vector<string>(maze[0].size(), "#"));
        dist[ball[0]][ball[1]] = 0;
        path[ball[0]][ball[1]] = "";
        string res = "";
        while(!q.empty()){
            auto [move, r, c, index, p] = q.top();
            q.pop();
            if(r == hole[0] && c == hole[1]){
                continue;
            }
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
                int count = 0;
                while(x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0){
                    count++;
                    if(x == hole[0] && y == hole[1]){
                        x = x + dx[i];
                        y = y + dy[i];
                        break;
                    }
                    x = x + dx[i];
                    y = y + dy[i];
                }
                x = x - dx[i];
                y = y - dy[i];
                if(x == ball[0] && y == ball[1])continue;
                if(dist[x][y] >= move+count){
                    string new_p = p;
                    if(i == 0)
                        new_p += "r";
                    else if(i == 1)
                        new_p += "l";
                    else if(i == 2)
                        new_p += "d";
                    else
                        new_p += "u";
                    if(path[x][y] == "#" || (path[x][y] > new_p)){
                        path[x][y] = new_p;
                        q.push({move+count,x,y,i, path[x][y]});
                        dist[x][y] = move+count;
                    }
                }
            }
        }
        if(path[hole[0]][hole[1]] != "#")
            return path[hole[0]][hole[1]];
        return "impossible";
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
[[0,0,0],[0,1,0],[0,0,0]]
[1,0]
[1,2]
*/
