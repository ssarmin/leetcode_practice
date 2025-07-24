//https://leetcode.com/problems/path-sum-ii
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        
        stack<tuple<TreeNode*, vector<int>, int>> s;
        s.push({root, {}, 0});
        
        vector<vector<int>> res;
        while(!s.empty()){
            auto [root, v, sum] = s.top();
            v.push_back(root->val);
            sum += root->val;
            s.pop();
            bool flag = true;
            if(root->left){
                flag = false;
                s.push({root->left, v, sum});
            }
            if(root->right){
                flag = false;
                s.push({root->right, v, sum});
            }
            if(flag){
                if(sum == targetSum){
                    res.push_back(v);
                }
            }
        } 
        return res;
    }
};
// Extra testcases:
// [10,2,11,0]
// 12
// [1,2]
// 1
// [1]
// 1
// [5,4,8,11,null,13,4,7,2,null,null,null,1]
// 22
// [1,2,3]
// 5
// [0]
// 0
// [1,2]
// 1
// [1,2]
// 2
// [-2,null,-3]
// -5
// [-2,null,-3]
// 0
// [8,9,-6,null,null,5,9]
// 7
// [1]
// 0
