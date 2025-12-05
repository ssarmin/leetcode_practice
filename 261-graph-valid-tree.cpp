//https://leetcode.com/problems/graph-valid-tree
class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int find(int node){
        int p = parent[node];
        while(p != node){
            node = p;
            p = parent[node];
        }
        return p;
    }
    bool combine(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2)
            return false;
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }else if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }else{
            parent[p2] = p1;
            rank[p1]++;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(auto e: edges){
            if(!combine(e[0], e[1]))
            return false;
        }
        int p1 = find(0); 
        for(int i=1; i<n; i++){
            if(p1 != find(i))
                return false;
        }
        return true;
    }
};

/*
4
[[2,3],[1,2],[1,3]]
5  
[[0,1], [1,2]]
4
[[0,1],[2,3]]
*/

/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.
 
*/
