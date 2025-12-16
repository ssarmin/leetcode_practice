// https://leetcode.com/problems/count-univalue-subtrees
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
    pair<int, int> update(int &count, unordered_map<TreeNode*, pair<int, int>> &m, TreeNode* root){
        if(root == nullptr){
            return {0, -1};
        }
        if(m.count(root))
            return m[root];
        if(root->left == nullptr && root->right == nullptr){
            m[root] = {root->val, 1};
            count++;
            return m[root];
        }else if(root->left && root->right){
            pair<int, int> left = update(count, m, root->left);
            pair<int, int> right = update(count, m, root->right);
            if(left.first == root->val && root->val == right.first && left.second != -1 && right.second != -1){
                m[root] = {root->val, (right.second + left.second + 1)};
                count++;
            }else{
                m[root] = {root->val, -1};
            }
        }else if(root->left){
            pair<int, int> left = update(count, m, root->left);
            if(left.first == root->val && left.second != -1){
                m[root] = {root->val, (left.second + 1)};
                count++;
            }else{
                m[root] = {root->val, -1};
            }
        }else if(root->right){
            pair<int, int> right = update(count, m, root->right);
            if(right.first == root->val && right.second != -1){
                m[root] = {root->val, (right.second + 1)};
                count++;
            }else{
                m[root] = {root->val, -1};
            }
        }
        return m[root];
    }
    int countUnivalSubtrees(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> m;
        int count = 0;
        pair<int, int> p = update(count, m, root);
        return count;
    }
};
/*
[]
[1]
[1,1,1]
[5,5,5,5,5,5,5]
[5,1,5,5,5,null,5]
[1,1,1,1,1,null,1]
[2,2,2,2,null,2,2]
[1,2,3]
[1,1,2,1,1,2,2]
[0,0,0,0,0,0,0]
[-1,-1,-1]
[-1,-1,0,-1,-1]
[3,3,3,3,3,null,3,null,null,3,3]
[1,null,1,null,1,null,1]
[7,7,7,7,7,7,8]
*/
