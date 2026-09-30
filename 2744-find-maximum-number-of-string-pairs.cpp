//https://leetcode.com/problems/find-maximum-number-of-string-pairs/
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> s;
        int res = 0;
        for (const auto& w : words) { // 1. Pass by const reference (no copy)
            if (s.count(w)) {
                res++;
                s.erase(w);
            } else {
                string rev(w.rbegin(), w.rend()); // 2. Reverse directly on creation
                s.insert(move(rev));              // 3. Move into set (no copy)
            }
        }

        return res;
    }
};

// ---------

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
