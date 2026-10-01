//https://leetcode.com/problems/implement-magic-dictionary/
class MagicDictionary {
public:
    struct trie{
        trie* child[26];
        bool end;
        string word;
    };
    MagicDictionary() {
    }
    
    trie* init(){
        trie* node = new trie();
        for(int i=0; i<26; i++){
            node->child[i] = nullptr;
        }
        node->end = false;
        return node;
    }
    trie* root = init();
    void build(string str){
        trie* node = root;
        if(node == nullptr){
            node = init();
        }
        for(auto c: str){
            int index = c - 'a';
            if(node->child[index] == nullptr){
                node->child[index] = init();
            }
            node = node->child[index];
        }
        node->end = true;
        node->word = str;
    }
    void buildDict(vector<string> dictionary) {
        for(auto d: dictionary){
            build(d);
        }
    }
    
    bool search(string searchWord) {
        bool flag = false;
        trie* node = root;
        if(node == nullptr)
            return false;
        queue<tuple<trie*, int, bool>> q;
        q.push({node, 0, flag});
        while(!q.empty()){
            auto [node, i, flag] = q.front();
            q.pop();
            if(node == nullptr)
                continue;
            if(i == searchWord.size()){
                if(flag && node->end)
                    return true;
                else
                   continue;
            }
            int index = searchWord[i] - 'a';
            for(int j=0; j<26; j++){
                if(node->child[j]){
                    if(j != index){
                        if(flag)continue;
                        q.push({node->child[j], i+1, !flag});
                    }else{
                        q.push({node->child[j], i+1, flag});
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

/*
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello","hallo","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello","hallo","leetcode"]], ["hello"], ["hallo"], ["hell"], ["leetcoded"]]
["MagicDictionary", "buildDict", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search"]
[[], [["a","b","ab","abc","abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj","abcdefghijawefe","aefawoifjowajfowafjeoawjfaow","cba","cas","aaewfawi","babcda","bcd","awefj"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["ab"], ["ba"], ["abc"], ["cba"], ["abb"], ["bb"], ["aa"], ["bbc"], ["abcd"], ["abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoaww"], ["abcabacbababdbadbfaejfoiawfjaojfaojefaowjfoawjfoawj"], ["caa"], ["bcb"]]

*/
