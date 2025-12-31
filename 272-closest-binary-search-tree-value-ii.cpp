//https://leetcode.com/problems/closest-binary-search-tree-value-ii
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
    void update(priority_queue<pair<double, int>> &pq, int k, TreeNode* root, double target){
        if(root == nullptr)
            return;
        double diff = fabs((double)root->val - target);
        if(pq.size() < k){
            pq.push({diff, root->val});
        }else if(pq.size() >= k && pq.top().first > diff){
            pq.pop();
            pq.push({diff, root->val});
        }
        update(pq, k, root->left, target);
        update(pq, k, root->right, target);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        update(pq, k, root, target);
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
