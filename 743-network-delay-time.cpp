//https://leetcode.com/problems/network-delay-time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> m;
        for(auto t: times){
            m[t[0]].push_back({t[1], t[2]});
        }
        int val = 0;
        unordered_map<int, int> m_cost;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//cost, node
        pq.push({0, k});
        m_cost[k] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto v: m[node]){
                if(!m_cost.count(v.first) || m_cost[v.first] > cost + v.second){
                    pq.push({cost+v.second, v.first});
                    m_cost[v.first] = cost + v.second;
                }
            }
        }
        for(auto it: m_cost){
            val = max(val, it.second);
        }
        return m_cost.size() == n? val:-1;
    }
};

// [[1,2,1],[2,3,1],[1,4,4],[3,4,1]]
// 4
// 1
// [[1,2,1],[2,1,3]]
// 2
// 2
// [[1,2,1],[2,3,7],[1,3,4],[2,1,2]]
// 4
// 1
// [[3,5,78],[2,1,1],[1,3,0],[4,3,59],[5,3,85],[5,2,22],[2,4,23],[1,4,43],[4,5,75],[5,1,15],[1,5,91],[4,1,16],[3,2,98],[3,4,22],[5,4,31],[1,2,0],[2,5,4],[4,2,51],[3,1,36],[2,3,59]]
// 5
// 5
// [[2,1,1],[2,3,1],[3,4,1]]
// 4
// 2
// [[4,2,76],[1,3,79],[3,1,81],[4,3,30],[2,1,47],[1,5,61],[1,4,99],[3,4,68],[3,5,46],[4,1,6],[5,4,7],[5,3,44],[4,5,19],[2,3,13],[3,2,18],[1,2,0],[5,1,25],[2,5,58],[2,4,77],[5,2,74]]
// 5
// 3
// [[1,2,1],[2,3,2],[1,3,2]]
// 3
// 1
