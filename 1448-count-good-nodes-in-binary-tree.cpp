//https://leetcode.com/problems/count-good-nodes-in-binary-tree
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
    void helper(TreeNode* root, int &count, int maxVal){
        if(root == nullptr)
            return;
        if(root->val >= maxVal){
            count++;
            maxVal = max(maxVal, root->val);
        }
        helper(root->left, count, maxVal);
        helper(root->right, count, maxVal);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        helper(root, count, INT_MIN);
        return count;
    }
};

// [-1,5,-2,4,4,2,-2,null,null,-4,null,-2,3,null,-2,0,null,-1,null,-3,null,-4,-3,3,null,null,null,null,null,null,null,3,-3]
