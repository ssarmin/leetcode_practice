//https://leetcode.com/problems/maximum-depth-of-binary-tree
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
    void find_max(int depth, TreeNode* root, int &max_depth){
        if(!root)
            return;
        max_depth = max(max_depth, depth);
        find_max(depth+1, root->left, max_depth);
        find_max(depth+1, root->right, max_depth);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int max_depth = 0;
        find_max(1, root, max_depth);
        return max_depth;
    }
};

//Time complexity: O(N)
/*
Extra testcases:
[3,9,20,null,null,15,7,null,8,5,null,9]
[]
[1]
[1,2,3,4,5]
[0,0,0,0,null,null,0,null,null,null,0]
*/
