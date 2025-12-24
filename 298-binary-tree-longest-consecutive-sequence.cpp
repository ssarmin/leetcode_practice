//https://leetcode.com/problems/binary-tree-longest-consecutive-sequence
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
    void update(TreeNode* root, int &max_val, int count, int prev){
        if(root == nullptr)
            return;
        if(prev == root->val - 1){
            count++;
        }else{
            count = 1;
        }
        max_val = max(max_val, count);
        update(root->left, max_val, count, root->val);
        update(root->right, max_val, count, root->val);
    }
    int longestConsecutive(TreeNode* root) {
        int max_val = 0;
        update(root, max_val, 0, INT_MAX);
        return max_val;
    }
};
/*
[1,null,3,2,4,null,null,null,5]
[2,null,3,null,4,null,5]
[5,4,3,2,1]
[1,2,3,4,5]
[3,2,4,1,null,3,5]
[10,11,12,13,null,null,14]
[-1,-2,-3,-4,-5]
[-5,-4,-3,-2,-1]
[1,2,3,null,null,4,5,null,null,6,7]
[100,99,101,98,null,null,102]
[1,null,2,null,3,null,4,null,5]
[5,6,7,null,null,8,9]
[0,-1,-2,-3,null,null,-1]
[1,2,3,4,null,null,5,5,6]
*/
