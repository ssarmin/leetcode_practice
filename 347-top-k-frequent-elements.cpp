//https://leetcode.com/problems/top-k-frequent-elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto n: nums){
            m[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto a: m){
            pq.push({a.second, a.first});
        }
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

/*
[1,2,1,2,1,2,3,1,3,2]
2
[-1,-1]
1
*/
