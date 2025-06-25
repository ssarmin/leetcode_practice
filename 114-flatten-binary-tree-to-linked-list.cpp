//https://leetcode.com/problems/flatten-binary-tree-to-linked-list
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flat(vector<TreeNode*> &v, TreeNode* root){
        if(!root)
            return;
        v.push_back(root);
        flat(v, root->left);
        flat(v, root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        vector<TreeNode*> v;
        flat(v, root);
        TreeNode* node = root;
        for(int i=1; i<v.size(); i++){
            node->left = NULL;
            node->right = v[i];
            node = node->right;
        }
    }
};
