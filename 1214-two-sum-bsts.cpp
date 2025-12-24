//https://leetcode.com/problems/two-sum-bsts
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
    bool bst(TreeNode* root, int val){
        if(root == nullptr)
            return false;
        if(root->val == val)
            return true;
        if(root->val > val){
            return bst(root->left, val);
        }
        return bst(root->right, val);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(bst(root2, target - root1->val))
            return true;
        return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
    }
};
/*
[2,1,4]
[1,0,3]
5
[2,1,4]
[1,0,3]
7
[5,3,7,2,4,6,8]
[10,6,15,3,8,12,20]
18
[5,3,7,2,4,6,8]
[10,6,15,3,8,12,20]
100
[0,-2,2,-3,-1,1,3]
[0,-2,2,-3,-1,1,3]
0
[0,-2,2,-3,-1,1,3]
[0,-2,2,-3,-1,1,3]
-6
[1,null,2,null,3,null,4]
[10,9,null,8,null,7]
11
[8,3,10,1,6,null,14,null,2,4,7,13]
[5,3,6,2,4,null,7,1]
*/
