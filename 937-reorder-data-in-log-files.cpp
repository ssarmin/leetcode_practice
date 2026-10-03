class Solution {
//https://leetcode.com/problems/reorder-data-in-log-files/
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        map<string, set<string>> m_letter;
        vector<int> digit;
        for(int index=0; index<logs.size(); index++){
            for(int i=0; i<logs[index].size(); i++){
                if(logs[index][i] == ' '){
                    string id(logs[index].begin(), logs[index].begin()+i);
                    string log(logs[index].begin()+i+1, logs[index].end());
                    if(log[0] >= '0' && log[0] <= '9'){
                        digit.push_back(index);
                    }else{
                        m_letter[log].insert(id);
                    }
                    break;
                }
            }
        }
        vector<string> res;
        res.resize(logs.size());
        int index = 0;
        for(auto a: m_letter){
            for(auto id: a.second){
                res[index++] = id + " " + a.first;
            }
        }
        for(auto i: digit){
            res[index++] = logs[i];
        }
        return res;
    }
};

/*
["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
["j mo", "5 m w", "g 07", "o 2 0", "t q h"]
["dig1 8 1 5 1"," let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
["1 n u", "r 527", "j 893", "6 14", "6 82"]
["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"]
*/
