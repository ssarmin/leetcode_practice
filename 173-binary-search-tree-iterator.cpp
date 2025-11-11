// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    vector<int> v;
    int index;
    void helper(TreeNode* root){
        if(!root)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    BSTIterator(TreeNode* root) {
        helper(root);
        index = 0;
    }
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        return (index < v.size());
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

["BSTIterator","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[7,null,15,9,16]],[],[],[],[],[],[],[],[]]
["BSTIterator","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[9,6,10,3,null,null,null]],[],[],[],[],[],[],[],[]]
["BSTIterator","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[8,5,10,3,6,9,12,1,null,null,7,null,null,11,null]],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
["BSTIterator","hasNext","next","hasNext"]
[[[1]],[],[],[]]
["BSTIterator","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[3,1,4,null,2]],[],[],[],[],[],[],[],[],[]]
