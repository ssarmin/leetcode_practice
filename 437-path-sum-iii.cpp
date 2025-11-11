//https://leetcode.com/problems/path-sum-iii
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
    void helper(TreeNode* root, unordered_map<long long, int> &m, int targetSum, long long sum, int &res){
        if(root == nullptr)
            return;
        sum += root->val;
        if(m.count(sum - targetSum)){
            res += m[sum - targetSum];
        }
        m[sum]++;
        helper(root->left, m, targetSum, sum, res);
        helper(root->right, m, targetSum, sum, res);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        m[0] = 1;
        int res = 0;
        helper(root, m, targetSum, 0, res);
        return res;
    }
};
// [1000000000,1000000000,null,294967296,null,1000000000,null,1000000000,null,1000000000]
// 0
// [2,3,4,5,6]
// 10
// [1,-2,-3]
// -1
// [0,1,1]
// 1
// [5,4,8,11,null,13,4,7,2,null,null,5,1]
// 22
// [1,1,1,2,-1,-1]
// 2
// [1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0]
// 2
// [1,-2,-3,1,3,-2,null,-1]
// 3
