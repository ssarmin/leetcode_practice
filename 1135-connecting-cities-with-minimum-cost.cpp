//https://leetcode.com/problems/connecting-cities-with-minimum-cost
class Solution {
public:
    unordered_map<int, int> parent;
    int find(int node){
        int p = parent[node];
        while(p != node){
            node = p;
            p = parent[node];
        }
        return p;
    }
    void unite(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2)
            return;
        parent[p1] = p2;
    }
    void init(int n){
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        init(n);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for(auto c: connections){
            unite(c[0], c[1]);
            pq.push({c[2], c[0], c[1]});
        }
        int p1 = find(1);
        for(int i=2; i<=n; i++){
            if(find(i) != p1)
                return -1;
        }
        int res = 0;
        parent.clear();
        init(n);
        while(!pq.empty()){
            auto [cost, x, y] = pq.top();
            pq.pop();
            if(find(x) == find(y))
                continue;
            unite(x, y);
            res += cost;
        }
        return res;
    }
};
/*
2
[[1,2,5]]
3
[[1,2,5],[2,3,6],[1,3,1]]
3
[[1,2,5],[2,3,6]]
4
[[1,2,3],[2,3,4],[3,4,5],[1,4,100]]
4
[[1,2,0],[2,3,0],[3,4,0],[1,3,10],[2,4,10]]
5
[[1,2,10],[1,3,8],[2,3,2],[2,4,5],[3,4,1],[4,5,7],[3,5,9]]
5
[[1,2,1],[2,3,1],[3,4,1],[4,5,1]]
6
[[1,2,3],[1,3,4],[2,3,2],[3,4,6],[4,5,5],[5,6,4],[4,6,1],[2,6,100]]
6
[[1,2,100000],[2,3,100000],[3,4,100000],[4,5,100000],[5,6,100000],[1,6,0]]
2
[[1,2,0]]
3
[[1,2,0],[2,3,0],[1,3,5]]
3
[[1,2,7]]
4
[[1,2,1],[1,2,0],[2,3,2],[3,4,3],[1,4,10]]
4
[[1,2,5],[2,3,5],[3,1,5],[3,4,1]]
5
[[1,2,3],[1,3,4],[1,4,5],[1,5,6]]
5
[[1,2,1],[2,3,2],[3,4,3],[4,5,4],[1,5,100],[2,5,50]]
6
[[1,2,2],[2,3,2],[3,4,2],[4,5,2],[5,6,2],[1,6,9],[2,5,1]]
6
[[1,2,0],[1,3,0],[1,4,0],[1,5,0],[1,6,0]]
7
[[1,2,10],[2,3,9],[3,4,8],[4,5,7],[5,6,6],[6,7,5],[1,7,1],[2,7,2],[3,7,3]]
7
[[1,2,5],[2,3,4],[3,4,3],[4,5,2],[5,6,1],[6,7,0],[1,3,10],[2,4,10],[3,5,10],[4,6,10],[5,7,10]]
*/
