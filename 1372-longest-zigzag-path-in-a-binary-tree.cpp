//https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
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
    pair<int, int> helper(TreeNode* root, int &max_val){
        if(root == nullptr){
            return {-1, -1};
        }
        auto left = helper(root->left, max_val);
        auto right = helper(root->right, max_val);
        int left_path = 1 + right.second;
        int right_path = 1 + left.first;
        max_val = max(max_val, max(left_path, right_path));
        return {left_path, right_path};
    }
    int longestZigZag(TreeNode* root) {
        int max_val = 0;
        helper(root, max_val);
        return max_val;
    }
};
/*
[6,9,7,3,null,2,8,5,8,9,7,3,9,9,4,2,10,null,5,4,3,10,10,9,4,1,2,null,null,6,5,null,null,null,null,9,null,9,6,5,null,5,null,null,7,7,4,null,1,null,null,3,7,null,9,null,null,null,null,null,null,null,null,9,9,null,null,null,7,null,null,null,null,null,null,null,null,null,6,8,7,null,null,null,3,10,null,null,null,null,null,1,null,1,2]
*/
