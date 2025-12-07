//https://leetcode.com/problems/maximal-network-rank
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> v_adj;
        v_adj.resize(n);
        for(auto r: roads){
            v_adj[r[0]].insert(r[1]);
            v_adj[r[1]].insert(r[0]);
        }
        int rank = 0;
        for(int i=0; i<n; i++){
            int conn_i = v_adj[i].size();
            for(int j=i+1; j<n; j++){
                int conn_j = v_adj[j].size();
                if(v_adj[i].count(j)){
                    rank = max(rank, conn_i + conn_j - 1);
                }else{
                    rank = max(rank, conn_i + conn_j);
                }
            }
        }
        return rank;
    }
};

/*
5
[[2,3],[0,3],[0,4],[4,1]]
8
[[4,6],[5,2],[3,5],[7,5],[7,6]]
8
[[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
*/
