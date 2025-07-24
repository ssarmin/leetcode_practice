
https://leetcode.com/problems/path-sum/description/
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        
        while(!s.empty()){
            root = s.top().first;
            int sum = s.top().second + root->val;
            s.pop();
            bool flag = true;
            if(root->left){
                flag = false;
                s.push({root->left, sum});
            }
            if(root->right){
                flag = false;
                s.push({root->right, sum});
            }
            if(flag){
                if(targetSum == sum)
                    return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool check(TreeNode* root, int currSum, int targetSum){
        if(root == NULL){
            return (currSum == targetSum);
        }
        if(root->left && root->right)
            return check(root->left, currSum+root->val, targetSum) || check(root->right, currSum+root->val, targetSum);
        if(root->left && !root->right)
            return check(root->left, currSum+root->val, targetSum);
        if(!root->left && root->right)
            return check(root->right, currSum+root->val, targetSum);
        return (currSum+root->val == targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(root->left && root->right)
            return check(root->left, root->val, targetSum) || check(root->right, root->val, targetSum);
        if(root->left && !root->right)
            return check(root->left, root->val, targetSum);
        if(!root->left && root->right)
            return check(root->right, root->val, targetSum);
        return (root->val == targetSum);
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
