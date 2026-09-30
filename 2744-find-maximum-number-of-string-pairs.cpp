//https://leetcode.com/problems/find-maximum-number-of-string-pairs/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int res = 0;
        for(auto w: words){
            if(s.count(w)){
                res++;
                s.erase(w);
            }else{
                reverse(w.begin(), w.end());
                s.insert(w);
            }
        }

        return res;
    }
};
