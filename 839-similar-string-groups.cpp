//https://leetcode.com/problems/similar-string-groups
class Solution {
public:
    unordered_map<string, string> parent;
    string find(string node){
        string p = parent[node];
        while(p != node){
            node = p;
            p = parent[node];
        }
        return p;
    }
    void unite(string node1, string node2){
        string p1 = find(node1);
        string p2 = find(node2);
        if(p1 == p2)
            return;
        parent[p1] = p2;
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> s;
        sort(strs.begin(), strs.end());
        for(int i=0; i<strs.size(); i++){
            parent[strs[i]] = strs[i];
        }
        for(int i=0; i<strs.size(); i++){
            for(int j=i+1; j<strs.size(); j++){
                if(strs[i] == strs[j]){
                    unite(strs[i], strs[j]);
                }else{
                    int diff = 0;
                    pair<int, int> p = {-1, -1};
                    for(int l=0; l<strs[i].size() && diff < 3; l++){
                        if(strs[i][l] != strs[j][l]){
                            diff++;
                            if(p.first == -1){
                                p.first = l;
                            }else{
                                p.second = l;
                            }
                        }
                    }
                    if(diff < 3){
                        string temp = strs[i];
                        swap(temp[p.first], temp[p.second]);
                        if(temp == strs[j]){
                            unite(strs[i], strs[j]);
                        }
                    }
                }
            }
        }
        for(int i=0; i<strs.size(); i++){
            s.insert(find(strs[i]));
        }
        return s.size();
    }
};
/*
["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaebdfc"]
["kccomwcgcs", "socgcmcwkc", "sgckwcmcoc", "coswcmcgkc", "cowkccmsgc", "cosgmccwkc", "sgmkwcccoc", "coswmccgkc", "kowcccmsgc", "kgcomwcccs"]
["koqnn","knnqo","noqnk","nqkon"]
["blw","bwl","wlb"]
["tars","rats","arts","star"]
["koqnn","knnqo","noqnk","nqkon"]
["abc","acb","bac","bca","cab","cba"]
["abcd","abdc","acbd","acdb","adbc","adcb"]
["aabb","abab","abba","baab","baba","bbaa"]
["xxyy","xyxy","yxxy","yyxx","yxyx"]
["abcdefghijkl","abcedfghijkl","abcdeghfijkl","bacdefghijkl","abcdefghijkl"]
["mnoopp","monopp","mnoopp","mnoopp"]
*/
