//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &m_in, int in_start, int in_end, int post_start, int post_end){
        if(in_start > in_end){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[post_end]);
        int in_root_index = m_in[root->val];
        int left_size = in_root_index - in_start;
        int right_size = in_end - in_root_index;
        root->left = build(inorder, postorder, m_in, in_start, in_root_index - 1, post_start, post_start+left_size-1);
        root->right = build(inorder, postorder, m_in, in_root_index + 1, in_end, post_end-right_size, post_end-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        unordered_map<int, int> m_in;
        for(int i=0; i<inorder.size(); i++){
            m_in[inorder[i]] = i;
        }
        return build(inorder, postorder, m_in, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};

// [10,9,3,11,15,20,7]
// [10,9,11,15,7,20,3]
// [15,20,3,7]
// [15,20,7,3]
// [9,3,15,20,7]
// [9,15,7,20,3]
// [7,6,5,4,3,2,1]
// [7,6,5,4,3,2,1]
// [1,2,3,4,5,6,7]
// [1,2,3,4,5,6,7]
// [4,2,5,1,6,8,9,7,3,10,12,11,13,14,15]
// [4,5,2,8,9,6,3,12,11,14,15,13,10,7,1]
// [15,20,25,8,12,30,10,5,35,40,45,50]
// [15,25,20,12,30,8,35,45,40,50,5,10]
