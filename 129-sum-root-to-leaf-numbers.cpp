//https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void update(TreeNode* root, int currSum, int &sum){
        if(!root)
            return;
        int num = currSum*10 + root->val;
        update(root->left, num, sum);
        update(root->right, num, sum);
        if(!root->left && !root->right)
            sum += num;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        int sum = 0;
        update(root->left, root->val, sum);
        update(root->right, root->val, sum);

        return sum;
    }
};

Extra testcases:
[9]
