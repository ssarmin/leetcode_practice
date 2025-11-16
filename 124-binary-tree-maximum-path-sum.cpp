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
//https://leetcode.com/problems/binary-tree-maximum-path-sum
class Solution {
public:
    int helper(TreeNode* root, int &max_val){
        if(root == nullptr)
            return INT_MIN;
        max_val = max(root->val, max_val);
        int left = INT_MIN;
        int right = INT_MIN;
        if(root->left == nullptr && root->right == nullptr){
            return root->val;
        }
        right = helper(root->right, max_val);
        left = helper(root->left, max_val);

        if(right != INT_MIN){
            max_val = max(right + root->val, max_val);
            max_val = max(right, max_val);
        }
        if(left != INT_MIN){
            max_val = max(left + root->val, max_val);
            max_val = max(left, max_val);
        }
        if(root->left && root->right)
            max_val = max(left + right + root->val, max_val);
        
        int val = root->val + max(left, right);
        val = max(root->val, val);
        return val;
    }
    int maxPathSum(TreeNode* root) {
        int max_val = root->val;
        int val = helper(root, max_val);
        return max_val;
    }
};
/*
[1,2,3]
[1,-2,3]
[5,4,8,11,null,13,4,7,2,null,null,null,1]
[1,-2,-3,1,3,-2,null,-1]
[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
[2,-1]
[1,2,null,3,null,4,null,5]
[-1,8,2,null,-9,0,null,null,null,-3,null,null,-9,null,2]
[10,-20,-30]
[2, -1, -2]
[1,1,1,1,1,1,1]
[1,2,3]
[1,2,1,10,10,1,1]
[-3]
[8,9,-6,null,null,5,9]
[-2,-1]
[-3]
[1,-2,-3,1,3,-2,null,-1]
[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
[-10,9,20,null,null,15,7]
[10,9,20,null,null,15,7]
[10,9,11,12,1,null,null,0,5,10,8]
[2,-1,-2]
[-3,-1,-2]
[-1,-2,10,-6,null,-3,-6]
[-1,null,9,-6,3,null,null,null,-2]
*/
