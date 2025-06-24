//https://leetcode.com/problems/binary-tree-right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int s=0; s<size; s++){
                TreeNode* temp = q.front();
                q.pop();
                if(s == 0){
                    res.push_back(temp->val);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
        }

        return res;
    }
};

// Extra testcase:
// [1,2,3,null,5,null,4,1,2,3,4,null,null,null,5]
