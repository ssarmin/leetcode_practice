//https://leetcode.com/problems/partition-labels
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> m;
        for(int i=0; i<s.size(); i++){
            if(m.count(s[i])){
                m[s[i]].second = i;
            }else{
                m[s[i]] = {i, i};
            }
        }
        vector<int> res;
        int start = -1;
        int end = -1;
        for(int i=0; i<s.size(); i++){
            if((start == -1 && end == -1) || !(m[s[i]].first >= start && m[s[i]].first <= end)){
                start = m[s[i]].first;
                end = m[s[i]].second;
                res.push_back(end-start+1);
            }else{
                end = max(end, m[s[i]].second);
                start = min(start, m[s[i]].first);
                res.back() = max(res.back(), end - start+1);
            }
        }
        return res;
    }
};


// "ababcbacadefegdehijhklij"
// "eccbbbbdec"
// "qiejxqfnqceocmy"
// "caedbdedda"
// "abababab"
