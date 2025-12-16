//https://leetcode.com/problems/maximum-average-subtree
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
    pair<int, int> update(TreeNode* root, unordered_map<TreeNode*, pair<int, int>> &m, double &max_val){
        if(root == nullptr)
            return {0, 0};
        if(m.count(root))
            return m[root];
        pair<int, int> left = update(root->left, m, max_val);
        pair<int, int> right = update(root->right, m, max_val);
        m[root] = {(left.first + root->val + right.first), (left.second + 1 + right.second)};
        max_val = max(max_val, (double)m[root].first / (double) m[root].second);
        return m[root];
    }
    double maximumAverageSubtree(TreeNode* root) {
        double max_val = 0.0;
        unordered_map<TreeNode*, pair<int, int>> m;
        pair<int, int> p = update(root, m, max_val);
        return max_val;
    }
};
/*
[5]
[5,6,1]
[1,2,3]
[10,5,15]
[10,5,15,3,7,12,18]
[1,1,1,1,1]
[100000,100000,100000]
[10,0,0,0,0]
[0,0,0,0,0]
[5,3,8,1,4,7,9]
[20,10,30,5,15,25,35]
[10,2,3,1,null,null,4]
[50,20,80,10,30,70,90,5,null,25,35,null,75,85,95]
[1,null,2,null,3,null,4,null,5]
[100000,99999,99998,99997,99996]
*/
