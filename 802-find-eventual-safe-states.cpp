//https://leetcode.com/problems/find-eventual-safe-states
class Solution {
public:
    char dfs(vector<char> &info, vector<bool> &in_stack, int index, const vector<vector<int>>& graph){
        if(info[index] != '-')
            return info[index];
        bool flag = true;
        for(auto i: graph[index]){
            if(info[i] == '-' && !in_stack[i]){
                in_stack[i] = true;
                info[i] = dfs(info, in_stack, i, graph);
                in_stack[i] = false;
            }
            if(info[i] == 'N' || in_stack[i]){
                flag = false;
            }
        }
        if(flag){
            info[index] = 'S';
        }else{
            info[index] = 'N';
        }
        return info[index];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<char> info(graph.size(), '-');
        vector<int> res;
        for(int i=0; i<graph.size(); i++){
            if(graph[i].size() == 0){
                info[i] = 'T';
                res.push_back(i);
                continue;
            }
            if(info[i] == '-'){
                vector<bool> in_stack(graph.size(), false);
                in_stack[i] = true;
                info[i] = dfs(info, in_stack, i, graph);
                in_stack[i] = false;
            }
            if(info[i] == 'S'){
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
/*
[[1,2],[2,3],[5],[0],[5],[],[]]
[[1,2,3,4],[1,2],[3,4],[0,4],[]]
[[],[0,2,3,4],[3],[4],[]]
[[],[0,1,2,3,4],[2,3],[4],[]]
[[4],[0,1,2,3,4],[2,3],[2,4],[1]]
[[0],[]]
[[0],[2,3,4],[3,4],[0,4],[]]
*/
