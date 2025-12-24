//https://leetcode.com/problems/sentence-similarity
class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size())
            return false;
        unordered_map<string, unordered_set<string>> m;
        for(auto s: similarPairs){
            m[s[0]].insert(s[1]);
            m[s[1]].insert(s[0]);
        }
        for(int i=0; i<sentence1.size(); i++){
            if(sentence1[i] == sentence2[i])continue;
            if(!m.count(sentence1[i]) || !m.count(sentence2[i]))
                return false;
            unordered_set<string> s1 = m[sentence1[i]];
            unordered_set<string> s2 = m[sentence2[i]];
            if((m.count(sentence1[i]) && s1.count(sentence2[i])) || (m.count(sentence2[i]) && s2.count(sentence1[i])))
                continue;
            else
                return false;
        }
        return true;
    }
};
/*
["an","extraordinary","meal"]
["a","good","dinner"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]
["one","excellent","meal"]
["one","good","dinner"]
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]
*/
