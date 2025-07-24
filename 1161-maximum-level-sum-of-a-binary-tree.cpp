//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
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
    int maxLevelSum(TreeNode* root) {
        int maxVal = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int maxLevel = 1;
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            while(size--){
                root = q.front();
                q.pop();
                sum += root->val;
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
            if(maxVal < sum){
                maxVal = sum;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};
// [-100,-200,-300,-20,-5,-10,null]
// [1,1,0,7,-8,-7,9]
// [989,null,10250,98693,-89388,null,null,null,-32127]
// [1,7,0,7,-8,null,null]
