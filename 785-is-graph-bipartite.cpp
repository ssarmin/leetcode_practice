//https://leetcode.com/problems/is-graph-bipartite
class Solution {
public:
    bool update(int node, vector<int> &node_value, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        node_value[node] = 1;
        while(!q.empty()){
            node = q.front();
            q.pop();
            for(auto nxt: graph[node]){
                if(node_value[node] == node_value[nxt])
                    return false;
                if(node_value[nxt] == 0){
                    q.push(nxt);
                    if(node_value[node] == 1){
                        node_value[nxt] = -1;
                    }else{
                        node_value[nxt] = 1;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> node_value(graph.size(), 0);
        for(int node = 0; node < graph.size(); node++){
            if(node_value[node] == 0){
                if(!update(node, node_value, graph))
                    return false;
            }
        }
        return true;
    }
};
/*
[[1],[0]]
[[1,2,3],[0,2],[0,1,3],[0,2]]
[[1,3],[0,2],[1,3],[0,2]]
[[4],[],[4],[4],[0,2,3]]
[[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
[[3,4,6],[3,6],[3,6],[0,1,2,5],[0,7,8],[3],[0,1,2,7],[4,6],[4],[]]
[[1,2,3],[0,3,4],[0,3],[0,1,2],[1]]
[[1,2,3,4],[0,2,3],[0,1,3,4],[0,1,2,4],[0,2,3]]
[[1],[0,3],[3],[1,2]]
*/
