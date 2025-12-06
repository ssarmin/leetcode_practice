//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree
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
    unordered_map<TreeNode*, TreeNode*> parent;
    void update_parent(TreeNode* root){
        if(root == nullptr)
            return;
        if(root->left){
            parent[root->left] = root;
            update_parent(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            update_parent(root->right);
        }
    }
    void going_down(int temp_k, TreeNode* target, vector<int> &res){
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(temp_k == 0){
                    res.push_back(node->val);
                }else{
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
            }
            temp_k--;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == nullptr)
            return {};
        parent[root] = nullptr;
        update_parent(root);
        vector<int> res;
        going_down(k, target, res);
        while(parent[target] != nullptr && k > 0){
            k--;
            TreeNode* p = parent[target];
            if(k == 0){
                res.push_back(p->val);
                break;
            }else if(k > 0){
                if(p->left && p->left != target){
                    going_down(k-1, p->left, res);
                }
                if(p->right && p->right != target){
                    going_down(k-1, p->right, res);
                }
            }
            target = p;
        }
        return res;
    }
};

/*
[0,1,null,null,2,null,3,null,4]
3
0
[0,null,1,2,5,null,3,null,null,null,4]
2
2
[0,1,2,null,3,null,5,4]
3
3
[0,2,1,null,null,3]
3
3
[0,5,1,null,null,2,6,null,3,null,null,4,null,7]
7
3
[0,1,null,null,2,null,3,null,4]
3
0
*/
