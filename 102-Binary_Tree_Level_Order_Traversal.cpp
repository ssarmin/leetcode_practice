//https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    void helper(TreeNode* root, vector<vector<int>> &v){
        if(root == NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left)
                    q.push(n->left);
                if(n->right)
                    q.push(n->right);
            }
            v.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        helper(root, v);
        return v;
    }
};
/*
Extra testcases:
[3,9,20,null,null,15,8,5,89,7]
[1,2,null,3,null,4,null,5]
[1,2,3,4,5]
[1,2,3,4,null,null,5]
*/
//Time complexity: O(n)
