// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<char, string> m;
        m['A'] = "CGT";
        m['C'] = "AGT";
        m['G'] = "ACT";
        m['T'] = "ACG";

        unordered_set<string> un_set(bank.begin(), bank.end());

        queue<string> q;
        q.push(startGene);
        int count = -1;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int s=0; s<size; s++){
                string str = q.front();
                if(str == endGene)
                    return count;
                q.pop();
                for(int i=0; i<str.size(); i++){
                    string match = m[str[i]];
                    for(auto ch: match){
                        string temp = str;
                        temp[i] = ch;
                        if(un_set.find(temp) != un_set.end()){
                            q.push(temp);
                            un_set.erase(temp);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

// "AACCTTGG"
// "AATTCCGG"
// ["AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"]
// "AAAAAAAA"
// "CCCCCCCC"
// ["AAAAAAAA","AAAAAAAC","AAAAAACC","AAAAACCC","AAAACCCC","AACACCCC","ACCACCCC","ACCCCCCC","CCCCCCCA"]
// "AACCGGTT"
// "AAACGGTA"
// ["AACCGATT","AACCGATA","AAACGATA","AAACGGTA"]
