//https://leetcode.com/problems/min-cost-to-connect-all-points
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> m;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                m[i].push_back({dist, j});
                m[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int total = 0;
        unordered_set<int> visit;
        while(visit.size() < points.size()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if(visit.count(node))
                continue;
            visit.insert(node);
            total += dist;

            for(auto a: m[node]){
                if(visit.count(a.second))
                    continue;
                pq.push({a.first, a.second});
            }
        }
        return total;
    }
};

// [[0,0],[2,2],[3,10],[5,2],[7,0]]
// [[3,12],[-2,5],[-4,1]]
// [[7,3],[1,5],[2,11],[4,4],[7,1]]
// [[0,0]]
// [[2,-3],[-17,-8],[13,8],[-17,-15]]
// [[0,0],[1,0],[0,1],[1,1]]
// [[2,2],[3,3],[4,4],[5,5]]
// [[0,0],[100,100],[200,200]]
// [[50,50],[150,150],[250,250]]
// [[1000,1000]]
// [[15,14],[-7,-1],[-19,16],[5,-6],[-14,18],[-10,0],[17,-1],[-4,4],[-15,14],[15,-8]]
