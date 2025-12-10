//https://leetcode.com/problems/shortest-path-visiting-all-nodes
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int goal = (1 << n) - 1;
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visit(n, vector<bool>((1<<n), false));
        for(int i=0; i<n; i++){
            int mask = (1 << i);
            q.push({i, mask, 0});
            visit[i][mask] = true;
        }

        while(!q.empty()){
            auto [node, mask, move] = q.front();
            q.pop();
            if(mask == goal)
                return move;
            for(auto nxt_node : graph [node]){
                int n_mask = mask | (1 << nxt_node);
                if(visit[nxt_node][n_mask])continue;
                q.push({nxt_node, n_mask, move+1});
                visit[nxt_node][n_mask] = true;
            }
        }
        return -1;
    }
};

/*
[[1,5,6,7,8,9,10,11],[0,2,4],[1,3,4],[2],[1,2],[0],[0],[0],[0],[0],[0],[0]]
[[3,8],[2,6,7],[1,6],[0,5],[7],[3,8],[1,2],[1,4,8],[0,5,7]]
[[1,2,3],[0],[0],[0]]
[[1],[0,2,4],[1,3,4],[2],[1,2]]
[[1,2,3,4],[0,2],[0,1],[0,5],[0,6],[3],[4]]
*/
