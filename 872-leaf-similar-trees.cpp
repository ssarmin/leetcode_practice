//https://leetcode.com/problems/leaf-similar-trees
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
    void helper(vector<int> &v, TreeNode* root){
        if(!root)
            return;
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(root->val);
            return;
        }
        helper(v, root->left);
        helper(v, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        helper(v1, root1);
        helper(v2, root2);
        if(v1.size() != v2.size())
            return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
};

// [5]
// [6,null,5]
// [93]
// [31,93,200]
// [20,1,null,11,76,20,13,93,8,95,null,null,null,null,null,null,73]
// [1,95,87,null,null,80,null,13,45,null,null,13,null,93,52,null,null,73]
// [47,44,32,10,37,null,75,88,null,null,null,78,87,null,null,91]
// [10,45,null,91,72,null,null,37,52,null,null,88,43,null,null,87]
// [17,84,41,81,38,79,null,30,17,62,19,1,27,null,null,94,72,null,17,null,65,null,39,null,null,null,84,null,null,2,null,36]
// [44,78,12,18,39,25,null,8,36,null,null,77,null,96,2,null,null,27,null,66,72,null,null,null,null,30,84]
// [26,50,49,null,90,27,81,null,null,51,6,91,null,85,6,6,40,null,4,43,null,null,null,99,84,null,null,42,97,null,null,null,null,null,86]
// [84,99,52,40,76,28,null,null,null,6,17,99,null,null,null,86,27,null,null,null,null,78,21,90,42,97,43]
// [46,56,80,76,44,67,62,null,41,32,82,71,12,65,63,93,2,34,43,87,61,89,36,63,16,60,8,95,null,1,59,null,null,55,78,10,27,null,null,80,8,22,87,45,42,34,93,37,6,null,41,null,null,52,26,null,68,15,24,32,76,84,66,35,8,81,65,94,null,50,null,72,80,59,32,57,15,55,54,25,92,10,62,21,61,null,16,81,null,null,23,40,61,null,null,35,24,23,25,null,null,null,null,49,89,null,null,75,null,25,null,null,65,48,null,null,null,54,52,null,62,null,null,57,null,22,null,60,57,null,null,47,44,20,66,42,null,85,null,91,77,34,null,86,46,68,29,89,null,null,null,19,91,14,60,40,39,null,null,null,null,null,null,null,null,58,10,null,null,null,52,99,57,76,null,69,100,null,99,29,92,97,36,null,29,null,null,null,null,29,52,57,96,91,null,null,null,null,29,null,null,53,18,null,null,null,null,null,32,null,7,null,79,null,null,null,58,null,null,null,null,null,null,79,66,61,null,null,43,61,null,83,78,55,7,null,null,84,null,13,null,null,null,null,null,52,null,null,41,91,null,null,null,null,41,null,49,null,null,38,9,null,3,null,null,null,null,null,null,33,25,20,null,null,96,99,null,null,null,8,55,null,null,null,null,null,null,null,58,null,46,17,null,33,null,38,null,18,null,null,null,null,null,null,null,null,null,59,11,56,null,62,null,null,null,null,59,1,null,null,null,null,null,67,null,null,null,null,null,null,null,null,null,39,13,67,null,null,null,22,null,60,85,null,null,null,87,null,null,31,43,57,null,null,null,null,93,null,null,null,null,null,null,null,null,62,85,null,null,null,null,null,15,null,null,null,73,null,null,80,null,null,null,null,null,null,null,null,null,null,1,54,null,null,null,16,null,null,10]
// [6,29,58,71,91,53,null,92,23,45,61,46,54,6,60,92,7,89,17,63,44,77,99,2,76,68,35,24,23,32,86,null,null,null,null,41,48,49,25,91,21,null,null,null,null,19,25,73,null,null,null,null,null,null,null,null,null,71,60,15,91,37,94,59,48,null,null,60,19,null,null,20,28,51,25,58,89,42,44,25,13,null,null,null,null,38,87,73,87,null,null,null,null,52,62,88,93,26,96,null,null,33,74,5,39,13,68,null,null,null,null,52,15,72,33,null,null,21,76,null,null,null,null,59,52,null,null,73,92,null,null,79,60,null,null,1,57,null,null,null,null,36,30,7,8,null,null,null,null,null,null,81,8,19,91,78,85,46,13,2,32,null,null,68,23,null,null,1,55,null,null,5,22,null,null,null,null,4,57,73,20,96,91,null,null,null,null,null,null,null,null,null,null,null,null,79,31,null,null,null,null,25,null,null,null,null,null,66,52,25,69,null,null,43,10,80,29,null,null,3,15,null,null,67,42,null,null,null,null,null,null,null,null,66,62,57,null,null,null,null,null,8,76,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,22,null,84,13]
// [42,5,24,57,87,93,20,90,67,88,63,89,28,90,76,null,null,73,53,43,null,72,71,69,35,null,null,null,99,91,53,null,null,5,null,40,91,59,61,99,92,21,null,78,43,null,null,3,null,null,null,98,null,3,65,null,null,null,44,null,30,36,95,1,null,null,null,1,36,40,31,null,24,null,null,null,null,93,31,12,42,80,21,null,12,48,null,null,null,26,98,27,null,13,61,68,31,null,null,null,43,null,null,43,19,null,55,91,null,null,null,null,null,87,null,58,10,76,99,99,4,7,43,32,7,11,84,84,73,null,null,null,1,null,null,null,null,80,null,null,null,58,27,11,88,12,38,91,null,null,69,37,null,null,null,78,23,77,89,59,47,87,27,23,null,77,47,49,87,null,null,null,null,61,null,36,54,6,8,null,null,48,35,42,null,null,55,90,null,null,null,61,57,73,84,null,null,45,14,null,null,97,55,7,6,18,98,null,71,null,54,null,3,30,89,14,null,null,null,null,null,null,null,null,null,25,39,null,null,11,17,null,null,null,null,34,41,98,49,null,null,null,null,27,10,null,null,100,null,null,null,null,null,7,null,64,27,null,43,null,53,null,null,19,65,34,null,null,null,83,81,null,34,41,66,95,null,90,null,73,null,null,null,null,10,null,null,null,36,70,32,null,25,null,null,56,57,null,null,71,null,null,null,null,12,null,null,94,39,null,null,null,null,null,null,null,null,null,29,76,74,null,null,null,96,null,null,null,null,null,null,25,13,null,null,29,null,53,13,null,null,null,null,null,null,47,95,72,98,null,null,null,null,16,null,31,16,1,null,null,null,null,74,null,null,93,null,1,30,93,null,null,null,null,null,null,null,77,null,null,null,null,12,null,null,null,null,71,35]
// [79,80,94,87,59,71,null,21,74,57,43,62,21,null,null,13,55,null,null,19,66,1,32,82,41,39,21,53,34,96,81,59,57,55,6,63,57,80,87,58,50,36,87,77,1,null,null,null,null,75,95,null,null,71,49,null,null,31,12,96,23,77,41,24,42,null,null,6,11,48,98,96,null,null,null,null,null,34,54,76,55,62,64,null,null,null,null,83,19,null,null,null,null,19,1,51,8,59,61,100,74,88,83,null,null,null,null,47,32,7,30,null,null,94,null,null,null,null,null,null,null,null,null,60,36,null,null,null,null,null,null,null,null,73,21,70,61,93,71,null,null,null,null,43,13,96,12,30,92,15,49,88,72,64,24,null,null,45,12,74,97,1,26,null,null,null,null,null,null,71,43,3,77,null,null,null,null,null,null,73,81,15,97,null,null,null,null,100,28,32,35,28,54,null,null,null,null,98,1,null,null,34,77,null,null,null,null,90,null,null,null,29,53,null,null,null,null,null,null,null,null,null,null,16,91,93,32,null,null,null,null,68,37,null,null,null,null,null,null,99,90,null,null,null,null,null,null,null,null,95,45,null,null,null,null,null,null,null,null,null,null,30,10,37,4,55,16,null,null,null,null,59,48,null,null,null,null,null,null,null,null,13,73,null,null,null,null,55,98]
