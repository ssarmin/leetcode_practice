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

// [[2,4],[1,3],[2,4],[1,3]]
// [[2,4,3],[1,3],[1,2,4],[1,3]]
// [[]]
// []
// [[2],[1]]
// [[2,3,4,14,19,35,59],[1,7,11,47,61,66],[1,24,41,52,68,98],[1,5,6,8,37,80],[4,9],[4,20,42,69],[2,10,17],[4,13,26,54,65,71,82],[5,12,16,23,38],[7,57],[2],[9,15,18,84],[8,32],[1,48],[12,46,58,76,85],[9,90],[7,21,30,70],[12,22],[1,27,86],[6,75,91],[17,49,51,99],[18,25,34,63,88],[9,40],[3,45,50,62],[22,36,72],[8,31],[19,28,33,55],[27,29],[28,97],[17],[26],[13],[27,64,83],[22],[1,39,44],[25],[4,60],[9],[35],[23,43],[3],[6],[40],[35,89],[24],[15],[2],[14,94],[21],[24],[21,53],[3,56,77],[51,87],[8,67],[27],[52],[10],[15],[1],[37],[2],[24],[22,74,79],[33,73],[8,93],[2],[54],[3,78],[6,95],[17],[8,81],[25],[64],[63],[20],[15,92],[52],[68],[63],[4],[71],[8],[33],[12],[15],[19],[53],[22],[44],[16],[20],[76],[65],[48,100],[69,96],[95],[29],[3],[21],[94]]
