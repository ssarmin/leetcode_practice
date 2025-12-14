//https://leetcode.com/problems/reverse-words-with-same-vowel-count
class Solution {
public:
    int get_count(string str){
        int count = 0;
        for(auto ch: str){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count++;
            }
        }
        return count;
    }
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        vector<string> v;
        while(ss >> word){
            v.push_back(word);
        }
        int count = get_count(v[0]);
        string res;
        res.resize(s.size());
        int index = 0;
        for(; index<v[0].size(); index++){
            res[index] = v[0][index];
        }
        
        for(int i=1; i<v.size(); i++){
            res[index] = ' ';
            index++;
            if(count == get_count(v[i])){
                for(int k=v[i].size()-1; k>=0; k--){
                    res[index] = v[i][k];
                    index++;
                }
            }else{
                for(int k=0; k<v[i].size(); k++){
                    res[index] = v[i][k];
                    index++;
                }
            }
        }
        return res;
    }
};
