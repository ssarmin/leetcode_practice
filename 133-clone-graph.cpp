//https://leetcode.com/problems/clone-graph/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* helper(Node* node, map<Node*, Node*> &m){
        if(node == NULL)
            return NULL;
        
        if(m.find(node) != m.end()){
            return m[node];
        }else{
            Node* n_node = new Node(node->val);
            m[node] = n_node;
            vector<Node*> v;
            for(auto nei: node->neighbors){
                v.push_back(helper(nei, m));
            }
            n_node->neighbors = v;
            return n_node;
        }
    }
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> m;
        return helper(node, m);
    }
};
