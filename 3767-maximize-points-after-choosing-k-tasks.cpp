// https://leetcode.com/problems/maximize-points-after-choosing-k-tasks
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<technique1.size(); i++){
            int val = technique2[i] - technique1[i];
            pq.push({val, i});
        }
        vector<bool> visit(technique1.size(), false);
        long long res = 0;
        while(k-- && !pq.empty()){
            int index = pq.top().second;
            res += technique1[index];
            visit[index] = true;
            pq.pop();
        }
        for(int i=0; i<technique1.size(); i++){
            if(visit[i])continue;
            res += max(technique1[i], technique2[i]);
            visit[i] = true;
        }
        return res;
    }
};
