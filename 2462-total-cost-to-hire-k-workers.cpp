//https://leetcode.com/problems/total-cost-to-hire-k-workers
class Solution {
public:
    void update_start(int &start_index, vector<int>& costs, int candidates, unordered_set<int> &deleted_index, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq_start){
        while(start_index < costs.size() && pq_start.size() < candidates){
            if(deleted_index.count(start_index)){
                start_index++;
                continue;
            }
            pq_start.push({costs[start_index], start_index});
            start_index++;
        }
    }

    void update_end(int &end_index, vector<int>& costs, int candidates, unordered_set<int> &deleted_index, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq_end){
        while(end_index >= 0 && pq_end.size() < candidates){
            if(deleted_index.count(end_index)){
                end_index--;
                continue;
            }
            pq_end.push({costs[end_index], end_index});
            end_index--;
        }
    }

    long long totalCost(vector<int>& costs, int k, int candidates) {
        unordered_set<int> deleted_index;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_start, pq_end;
        int start_index = 0;
        for(int i=0; i<candidates; i++){
            pq_start.push({costs[i], i});
            start_index++;
        }
        int end_index = costs.size()-1;
        for(int i=costs.size()-1; i + candidates >= costs.size(); i--){
            pq_end.push({costs[i], i});
            end_index--;
        }
        long long ans = 0;
        while(k > 0){
            k--;
            while(!pq_start.empty() && deleted_index.count(pq_start.top().second)){
                pq_start.pop();
                update_start(start_index, costs, candidates, deleted_index, pq_start);
            }
            while(!pq_end.empty() && deleted_index.count(pq_end.top().second)){
                pq_end.pop();
                update_end(end_index, costs, candidates, deleted_index, pq_end);
            }
            if(!pq_start.empty() && !pq_end.empty()){
                if(pq_start.top().first < pq_end.top().first || (pq_start.top().first == pq_end.top().first && pq_start.top().second < pq_end.top().second)){
                    ans += pq_start.top().first;
                    deleted_index.insert(pq_start.top().second);
                    pq_start.pop();
                    update_start(start_index, costs, candidates, deleted_index, pq_start);
                }else{
                    ans += pq_end.top().first;
                    deleted_index.insert(pq_end.top().second);
                    pq_end.pop();
                    update_end(end_index, costs, candidates, deleted_index, pq_end);
                }
            }else if(pq_start.empty()){
                ans += pq_end.top().first;
                deleted_index.insert(pq_end.top().second);
                pq_end.pop();
                update_end(end_index, costs, candidates, deleted_index, pq_end);
            }else{
                ans += pq_start.top().first;
                deleted_index.insert(pq_start.top().second);
                pq_start.pop();
                update_start(start_index, costs, candidates, deleted_index, pq_start);
            }
        }
        return ans;
    }
};


[ 1, 2, 3, 4, 5, 6 ,7 ,8, 9 ]
2
3
[17,12,10,2,7,2,11,20,8]
3
4
[1,2,4,1]
3
3
[1,2,3,4,5,6,7,8,9]
2
3
[50,80,34,9,86,20,67,94,65,82,40,79,74,92,84,37,19,16,85,20,79,25,89,55,67,84,3,79,38,16,44,2,54,58]
7
12
[2,2,2,2,3,3,3,3,1,1,1,1,2,2,2,2,2]
6
3
[10,11,1,10]
2
1
[2,2,9,9,1,1,2,2]
4
1
[31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58]
11
2
[50,80,34,86,67,94,65,82,40,79,74,92,84,37,19,16,85,79,25,89,55,67,84,79,38,44,54,58]
7
12
[69,10,63,24,1,71,55,46,4,61,78,21,85,52,83,77,42,21,73,2,80,99,98,89,55,94,63,50,43,62,14]
21
31
[57,33,26,76,14,67,24,90,72,37,30]
11
2
[25,65,41,31,14,20,59,42,43,57,73,45,30,77,17,38,20,11,17,65,55,85,74,32,84]
24
8

