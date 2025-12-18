//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
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
    void update(map<int, map<int, vector<int>>> &m, TreeNode* root, int row, int col){
        if(root == nullptr)
            return;
        m[col][row].push_back(root->val);
        update(m, root->left, row+1, col-1);
        update(m, root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> m;
        update(m, root, 0, 0);
        vector<vector<int>> res;
        for(auto c: m){
            vector<int> v;
            for(auto r: c.second){
                vector<int> temp = r.second;
                sort(temp.begin(), temp.end());
                v.insert(v.end(), temp.begin(), temp.end());
            }
            res.push_back(v);
        }
        return res;
    }
};

/*
[0,2,1,3,null,null,null,4,5,null,7,6,null,10,8,11,9]
[0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
[3,1,4,0,2,2]
*/
