//https://leetcode.com/problems/validate-binary-search-tree
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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(v, root);
        for(int i=1; i<v.size(); i++){
            if(v[i-1] >= v[i])
                return false;
        }
        return true;
    }
};
/*
Extra test cases:
// [120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]
// [1,null,null]
// [1,null]
// [-2147483648,-2147483648]
*/
