//https://leetcode.com/problems/delete-nodes-and-return-forest
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
    bool helper(int val, TreeNode* root, TreeNode* parent, queue<pair<TreeNode*, TreeNode*>> &q){
        if(root == nullptr)
            return false;
        if(parent == nullptr && root->val != val){
            q.push({root, nullptr});
        }
        if(root->val == val){
            if(root->left){
                q.push({root->left, nullptr});
            }
            if(root->right){
                q.push({root->right, nullptr});
            }
            if(parent != nullptr){
                if(parent->left == root){
                    parent->left = nullptr;
                }
                if(parent->right == root){
                    parent->right = nullptr;
                }
            }
            return true;
        }else{
            return helper(val, root->left, root, q) || helper(val, root->right, root, q);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        for(auto d: to_delete){
            int size = q.size();
            while(size--){
                auto [root, p] = q.front();
                q.pop();
                if(helper(d, root, p, q)){
                    break;
                }
            }
        }
        vector<TreeNode*> res;
        while(!q.empty()){
            res.push_back(q.front().first);
            q.pop();
        }
        return res;
    }
};
/*
[1,5,2,null,null,null,3,4]
[1,5]
[1,2,3,null,null,null,4]
[2,1]
[1,2,null,4,3]
[2,3]
[1,2,3,4,5,6,7]
[3,5]
[1,2,3,4,5,6,7]
[1]
[1,2,3,4,5,6,7]
[4,6]
[1,null,2,null,3,null,4]
[2,3]
[1,2,null,3,null,4,null]
[1,3]
[10,5,15,3,7,12,18]
[15,7]
[8,3,10,1,6,null,14,null,null,4,7,13]
[3,14]
[1,2,3,null,4,null,5]
[2]
[50,30,70,20,40,60,80]
[20,30,70]
[1,2,3,4,null,null,5,6,7]
[4,5,2]
[100,50,150,25,75,125,175,null,30]
[50,125]
[1]
[1]
[1,2,3,4,5,null,6,null,null,7,8]
[3,7,8]
*/
