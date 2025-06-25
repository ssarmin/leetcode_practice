//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void update(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root->left){
            parent[root->left] = root;
            update(root->left, parent);
        }
            
        if(root->right){
            parent[root->right] = root;
            update(root->right, parent);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
        update(root, parent);
        unordered_map<TreeNode*, bool> m;

        while(p != root){
            m[p] = true;
            p = parent[p];
        }

        while(q != root){
            if(m.find(q) != m.end())
                return q;
            q = parent[q];
        }

        return root;
    }
};
