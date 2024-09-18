//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    void order(TreeNode* root, vector<int> &v){
        if(!root)
            return;
        order(root->left, v);
        v.push_back(root->val);
        order(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        order(root, v);
        return v[k-1];
    }
};

//Time complexity: O(N)
