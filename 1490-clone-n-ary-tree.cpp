//https://leetcode.com/problems/clone-n-ary-tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> clone;
    Node* cloneTree(Node* root) {
        if(root == nullptr)
            return nullptr;
        if(clone.count(root))
            return clone[root];
        clone[root] = new Node(root->val);
        for(auto c: root->children){
            clone[root]->children.push_back(cloneTree(c));
        }
        return clone[root];
    }
};
