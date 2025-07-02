//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        if(p->val > q->val){
            high = p;
            low = q;
        }else{
            high = q;
            low = p;
        }
        while(root){
            if(root->val >= low->val && root->val <= high->val){
                return root;
            }else if(root->val > high->val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return nullptr;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p, q);
        }
        while(root){
            if(root->val >= p->val && root->val <= q->val){
                return root;
            }else if(root->val > q->val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return nullptr;
    }
};
// [2,1]
// 1
// 2
