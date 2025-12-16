//https://leetcode.com/problems/valid-word-square
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int size = words[0].size();
        for(int i=1; i<words.size(); i++){
            if(size < words[i].size())
                return false;
            size = words[i].size();
        }
        for(int i=0; i<words.size(); i++){
            string str = "";
            for(auto w: words){
                if(i >= w.size())
                    break;
                str += w[i];
            }
            if(str != words[i]){
                return false;
            }
        }
        return true;
    }
};
