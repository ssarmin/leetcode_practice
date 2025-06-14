// https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    void inorder(vector<int> &v, TreeNode* root){
        if(!root)
            return;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(v, root);
        int minV = INT_MAX;
        for(int i=1; i<v.size(); i++){
            minV = min(minV, v[i] - v[i-1]);
        }
        return minV;
    }
};

// Extra testcases:
// [11,0,48,null,null,22,90]
