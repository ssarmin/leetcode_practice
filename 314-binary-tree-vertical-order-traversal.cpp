//https://leetcode.com/problems/binary-tree-vertical-order-traversal
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [node, pos] = q.front();
                q.pop();
                m[pos].push_back(node->val);
                if(node->left){
                    q.push({node->left, pos-1});
                }
                if(node->right){
                    q.push({node->right, pos+1});
                }
            }
        }
        vector<vector<int>> res;
        for(auto a: m){
            res.push_back(a.second);
        }
        return res;
    }
};
