//https://leetcode.com/problems/delete-node-in-a-bst
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
    TreeNode* findMin(TreeNode* root){
        if(root->left){
            return findMin(root->left);
        }else{
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }else if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            }else if(root->left == nullptr){
                return root->right;
            }else if(root->right == nullptr){
                return root->left;
            }else{
                TreeNode* node = findMin(root->right);
                root->val = node->val;
                root->right = deleteNode(root->right, node->val);
            }
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

// [50,30,60,20,40,null,70,null,null,35,45]
// 30
// [5,3,6,2,4,null,7]
// 3
// [5,3,6,2,4,null,7]
// 0
// []
// 0
// [5,2,6,null,4,null,7]
// 0
// [2,0,33,null,1,25,40,null,null,11,31,34,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6]
// 33
// [0]
// 0
