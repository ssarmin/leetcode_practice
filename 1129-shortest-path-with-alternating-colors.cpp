//https://leetcode.com/problems/shortest-path-with-alternating-colors
class Solution {
public:
    int update(const int n, int dest, char color, const vector<unordered_set<int>> &v_red, const vector<unordered_set<int>> &v_blue){
        queue<pair<int, char>> q;
        q.push({0, color});
        int count = 0;
        unordered_map<int, set<pair<int, char>>> m_visit;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [node, color] = q.front();
                q.pop();
                if(node == dest){
                    return count;
                }
                if(color == 'R'){
                    for(auto nxt: v_blue[node]){
                        if(m_visit.count(node) && m_visit[node].count({nxt, 'B'}))continue;
                        m_visit[node].insert({nxt, 'B'});
                        q.push({nxt, 'B'});
                    }
                }else{
                    for(auto nxt: v_red[node]){
                        if(m_visit.count(node) && m_visit[node].count({nxt, 'R'}))continue;
                        m_visit[node].insert({nxt, 'R'});
                        q.push({nxt, 'R'});
                    }
                }
            }
            count++;
        }
        return INT_MAX;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<unordered_set<int>> v_red, v_blue;
        v_red.resize(n);
        v_blue.resize(n);
        for(auto r: redEdges){
            v_red[r[0]].insert(r[1]);
        }

        for(auto r: blueEdges){
            v_blue[r[0]].insert(r[1]);
        }

        vector<int> res;
        res.resize(n);
        for(int i=0; i<n; i++){
            int val = min(update(n, i, 'R', v_red, v_blue), update(n, i, 'B', v_red, v_blue));
            res[i] = (val == INT_MAX)? -1: val;
        }
        return res;
    }
};
/*
5
[[0,1],[1,2],[2,3],[3,4]]
[[1,2],[2,3],[3,1]]
7
[[0,1],[0,2],[1,4],[1,2],[2,3]]
[[1,2],[2,5],[3,6]]
3
[[0,1],[1,2]]
[[1,1]]
3
[[1,0]]
[[2,1]]
7
[[0,1],[1,2],[2,3],[3,4]]
[[1,2],[2,3],[3,1]]
6
[[4,1],[3,5],[5,2],[1,4],[4,2],[0,0],[2,0],[1,1]]
[[5,5],[5,0],[4,4],[0,3],[1,0]]
*/
