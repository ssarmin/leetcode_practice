//https://leetcode.com/problems/serialize-and-deserialize-binary-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        string str = to_string(root->val);
        if(root->left){
            str = "(" + serialize(root->left) + ")" + str;
        }
        if(root->right){
            str = str + "{" + serialize(root->right) + "}";
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        int val = 0;
        int l_index = -1;
        int r_index = -1;
        int count = 0;
        bool neg = false;
        for(int i=0; i<data.size(); i++){
            if(count == 0 && isdigit(data[i])){
                val = val*10 + data[i] - '0';
            }
            if(count == 0 && data[i] == '-'){
                neg = true;
            }
            if(count == 0 && data[i] == '{'){
                r_index = i;
                break;
            }
            if(data[i] == '('){
                count++;
            }
            if(data[i] == ')'){
                l_index = i;
                count--;
            }
        }
        if(neg){
            val = -1*val;
        }
        TreeNode* root = new TreeNode(val);
        string left = "";
        string right = "";
        if(l_index != -1){
            left = data.substr(1, l_index-1);
        }
        if(r_index != -1){
            right = data.substr(r_index+1);
            right.pop_back();
        }
        root->left = deserialize(left);
        root->right = deserialize(right);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// [1,2,3,null,null,4,5]
// []
// [1]
// [1, null, 2]
// [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
// [1,2,-13,null,null,4,5]
// [1,2,3,null,null,4,5,6,7]
// [1,2,3,null,null,4,null,null,5,null,null]
