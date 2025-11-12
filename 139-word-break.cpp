//https://leetcode.com/problems/word-break
class Solution {
public:
    struct Trie{
        Trie* child[26];
        bool isWord;
    };
    Trie* root = nullptr;
    Trie* init(){
        Trie* node = new Trie();
        for(int i=0; i<26; i++){
            node->child[i] = nullptr;
        }
        node->isWord = false;
        return node;
    }
    bool check(string &s, Trie* node){
        if(node == nullptr)
            return false;
        queue<Trie*> q;
        q.push(node);
        for(auto ch: s){
            int index = ch - 'a';
            int size = q.size();
            bool flag = false;
            while(size--){
                node = q.front();
                q.pop();
                if(node->child[index]){
                    q.push(node->child[index]);
                    flag = flag | node->child[index]->isWord;
                }
            }
            if(flag){
                q.push(root);
            }
        }
        while(!q.empty()){
            if(q.front()->isWord)
                return true;
            q.pop();
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        root = init();
        for(auto word: wordDict){
            Trie* node = root;
            for(auto ch: word){
                int index = ch - 'a';
                if(node->child[index] == nullptr){
                    node->child[index] = init();
                }
                node = node->child[index];
            }
            node->isWord = true;
        }
        return check(s, root);
    }
};
// "a"
// ["b"]
// "aaaaaaa"
// ["aaaa","aa"]
// "aaaaaaa"
// ["aaaa","aaa"]
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
// ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
