//https://leetcode.com/problems/find-leaves-of-binary-tree
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
    pair<int, int> update(map<int, vector<int>> &m, TreeNode* root){
        if(root == nullptr)
            return {-1, -1};
        if(root->left == nullptr && root->right == nullptr){
            m[0].push_back(root->val);
            return {0, 0};
        }
        pair<int, int> left = update(m, root->left);
        pair<int, int> right = update(m, root->right);
        pair<int, int> p = {max(left.first, left.second)+1, max(right.first, right.second)+1};
        m[max(p.first, p.second)].push_back(root->val);
        return p;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int, vector<int>> m;
        pair<int, int> p = update(m, root);
        vector<vector<int>> res;
        for(auto a: m){
            res.push_back(a.second);
        }
        return res;
    }
};
/*
[1,3,4,2,null,6,5,null,null,null,null,null,7]
[1,2,3,4,5,6,7]
[1,2,3,4,5,null,6,7,null,null,null,null,null,8]
[1,null,2,null,3,null,4,null,5,null,6,null,7]
[1,2,null,3,null,4,null,5,null,6,null,7]
[1,2,3,null,4,5,null,null,6]
[10,5,15,3,7,12,18,1,null,6,8,null,13,17,20]
[8,3,10,1,6,9,14,null,2,4,7,null,null,13,15]
[50,30,70,20,40,60,80,10,25,35,45,55,65,75,90]
[1,2,3,4,null,5,6,null,null,7,8,null,null,9,10]
[1,null,5,3,null,2,4]
[2,1,5,null,null,3,6,null,4]
[7,2,9,1,3,8,12,null,null,null,6,null,null,10,null,4,null,null,11,null,5]
[1,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9,null,10,null,11,null,12]
*/
