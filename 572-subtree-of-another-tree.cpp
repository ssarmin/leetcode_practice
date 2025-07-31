//https://leetcode.com/problems/subtree-of-another-tree
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
    bool helper(TreeNode* root, TreeNode* subRoot){
        if(!root && root == subRoot)
            return true;
        if(!root && root != subRoot || !subRoot && subRoot != root)
            return false;
        if(root->val != subRoot->val)
            return false;
        return helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && root == subRoot)
            return true;
        if(!root && root != subRoot || !subRoot && subRoot != root)
            return false;
        bool flag = false;
        if(root->val == subRoot->val){
            flag = helper(root->left, subRoot->left) && helper(root->right, subRoot->right);
        }
        if(flag){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// [3,4,5,1,2]
// [4,1,2]
// [3,4,5,1,2,null,null,null,null,0]
// [4,1,2]
// [3,4,5,1,null,2]
// [3,1,2]
// [3,4,5,1,2,null,null,null,null,0,null,null,4,1,2]
// [4,1,2]
// [3,4,5,1,2,null,null,null,null,0,null,null,4,1,2]
// [4]
