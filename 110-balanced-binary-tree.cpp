//https://leetcode.com/problems/balanced-binary-tree
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
    bool flag = true;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!flag){
            return -1;
        }
        int left = 0;
        int right = 0;
        if(root->left){
            left = 1+helper(root->left);
        }
        if(root->right){
            right = 1+helper(root->right);
        }
        if(abs(left - right) > 1){
            flag = false;
            return -1;
        }
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int val = helper(root);
        return flag;
    }
};
// [1,2,2,3,null,null,3,4,null,null,4]
// [1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
// [1,null,2,null,3]
// [1,2,3,4,5,6,null,8]
// [1,2,3,4,5,null,6,7,null,null,null,null,8]
// [1,2,3,4,null,5,null,6,7,9]
// [1,2,3,4,5,6,null,7]
