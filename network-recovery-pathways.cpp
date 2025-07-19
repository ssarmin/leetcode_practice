//https://leetcode.com/contest/biweekly-contest-161/problems/network-recovery-pathways
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        vector<vector<pair<int, int>>> adj_list(online.size());

        for(auto e: edges){
            if(online[e[0]] && online[e[1]]){
                adj_list[e[0]].push_back({e[1], e[2]});//node, cost
            }
        }
        
        queue<tuple<int, int, long long>> s;//node, min_val, sum
        int maxVal = INT_MIN;
        s.push({0, INT_MAX, 0});
        unordered_map<int, unordered_map<int, long long>> m_visit;//node, min_val, cost
        while(!s.empty()){
            auto [node, min_val, total] = s.front();
            s.pop();
            if(total > k)
                continue;
            if(node == online.size()-1){//dest
                maxVal = max(maxVal, min_val);
                continue;
            }
            if(m_visit[node].count(min_val) && m_visit[node][min_val] <= total)
                continue;
            m_visit[node][min_val] = total;
            
            for(int i=0; i<adj_list[node].size(); i++){
                int n_node = adj_list[node][i].first;
                int cost = adj_list[node][i].second;
                s.push({n_node, min(min_val, cost), total+cost});
            }
        }

        return (maxVal == INT_MIN)? -1:maxVal;
    }
};
