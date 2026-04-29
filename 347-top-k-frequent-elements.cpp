//https://leetcode.com/problems/top-k-frequent-elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        for(auto n: nums){
            m[n]++;
        }
        for(auto a: m){
            pq.push({a.second, a.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

/*
Time Complexity Analysis
The total time complexity is $O(N \log k)$, where $N$ is the number of elements in the input array and $k$ is the number of top elements requested.Step-by-Step Breakdown:

Counting Frequencies: You iterate through the nums array once to populate the unordered_map. Complexity: $O(N)$

Building the Min-Heap: You iterate through the map (which has at most $N$ unique elements). For each element, you perform a push and potentially a pop on the priority queue.Since the size of the priority queue is capped at $k$, each heap operation (push/pop) takes $O(\log k)$.Complexity: $O(N \log k)$

Extracting Results: You extract $k$ elements from the heap to build the final vector.
Complexity: $O(k \log k)$Total:$O(N) + O(N \log k) + O(k \log k)$ simplifies to $O(N \log k)$.

Space Complexity Analysis
The total space complexity is $O(N + k)$, which simplifies to $O(N)$.
unordered_map: Stores up to $N$ unique elements and their counts. $\to O(N)$
priority_queue: Stores at most $k$ elements. $\to O(k)$
Result Vector: Stores $k$ elements. $\to O(k)$
*/
/*
[1,2,1,2,1,2,3,1,3,2]
2
[-1,-1]
1
*/
