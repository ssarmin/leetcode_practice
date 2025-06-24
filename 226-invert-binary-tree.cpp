// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* node = root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        node->left = invertTree(r);
        node->right = invertTree(l);
        return node;
    }
};

//[4,2,7,1,3,6,9,2,1,3,null,23,3,1,4,6,null,1,23,4,51,2,34,1]
