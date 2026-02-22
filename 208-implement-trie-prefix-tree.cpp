// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    Trie* children[26];
    bool isLeaf;

    Trie() {
        isLeaf = false;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
    }
    
    Trie* root = NULL;

    void insert(string word) {
        if(root == NULL){
            root = new Trie();
        }
        Trie* node = root;
        
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == NULL){
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isLeaf = true;
    }
    
    bool search(string word) {
        Trie* node = root;
        if(root == NULL){
            return false;
        }
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == NULL){
                return false;
            }
            node = node->children[index];
        }

        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie* node = root;
        if(root == NULL)
            return false;
        for(char ch: prefix){
            int index = ch - 'a';
            if(node->children[index] == NULL){
                return false;
            }
            node = node->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Time complexity: O(n) for each cases

/*
["Trie","insert","insert","search","startsWith"]
[[],["a"],["pa"],["p"],["p"]]
["Trie","insert","search","startsWith"]
[[],["a"],["a"],["a"]]
["Trie","startsWith"]
[[],["a"]]
["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
["Trie","insert","insert","search"]
[[],["a"],["pa"],["p"]]
["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["apple"],["app"],["app"]]
*/
