https://leetcode.com/problems/repeated-dna-sequences
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
        unordered_map<string, int> m;
        for(int i=0; i<s.size()-9; i++){
            string str = s.substr(i, 10);
            m[str]++;
        }
        vector<string> v;
        for(auto it: m){
            if(it.second > 1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};

// "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT"
// "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// "AAAAAAAAAAA"
// "AAAAAAAAAAAAA"
// "A"
