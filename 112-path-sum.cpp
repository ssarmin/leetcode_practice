
https://leetcode.com/problems/path-sum/description/
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
    bool check(TreeNode* root, int currSum, int targetSum){
        if(root == NULL){
            return (currSum == targetSum);
        }
        if(root->left && root->right)
            return check(root->left, currSum+root->val, targetSum) || check(root->right, currSum+root->val, targetSum);
        if(root->left && !root->right)
            return check(root->left, currSum+root->val, targetSum);
        if(!root->left && root->right)
            return check(root->right, currSum+root->val, targetSum);
        return (currSum+root->val == targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(root->left && root->right)
            return check(root->left, root->val, targetSum) || check(root->right, root->val, targetSum);
        if(root->left && !root->right)
            return check(root->left, root->val, targetSum);
        if(!root->left && root->right)
            return check(root->right, root->val, targetSum);
        return (root->val == targetSum);
    }
};


Extra testcases:
[1,2]
1
