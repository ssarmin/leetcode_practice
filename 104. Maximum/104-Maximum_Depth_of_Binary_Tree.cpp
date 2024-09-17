//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
    void getLen(TreeNode* root, int l, int &mLen){
        mLen = max(mLen, l);
        if(root == NULL)
            return;
        getLen(root->left, l+1, mLen);
        getLen(root->right, l+1, mLen);
    }
    int maxDepth(TreeNode* root) {
        int len = 0;
        getLen(root, 0, len);
        return len;   
    }
};

//Time complexity: O(N)
/*
Extra testcases:
[3,9,20,null,null,15,7,null,8,5,null,9]
[]
[1]
[1,2,3,4,5]
[0,0,0,0,null,null,0,null,null,null,0]
*/
