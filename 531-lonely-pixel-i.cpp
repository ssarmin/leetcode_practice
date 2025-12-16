//https://leetcode.com/problems/lonely-pixel-i
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int, int> rows, cols;
        vector<pair<int, int>> v;
        for(int r=0; r<picture.size(); r++){
            for(int c=0; c<picture[0].size(); c++){
                if(picture[r][c] == 'B'){
                    rows[r]++;
                    cols[c]++;
                    v.push_back({r,c});
                }
            }
        }
        int count = 0;
        for(auto p: v){
            if(rows[p.first] == 1 && cols[p.second] == 1){
                count++;
            }
        }
        return count;
    }
};
/*
[["W","W","B"],["W","B","W"],["B","W","W"]]
[["B","B","B"],["B","B","W"],["B","B","B"]]
[["B"]]
[["W"]]
[["B","W","W"],["W","W","W"],["W","W","B"]]
[["W","B","W"],["B","W","B"],["W","B","W"]]
[["B","W","B"],["W","W","W"],["B","W","B"]]
[["B","B","W","B"],["B","W","B","B"],["W","B","B","B"],["B","B","B","W"]]
[["W","W","W","W"],["W","B","W","W"],["W","W","W","W"],["W","W","W","W"]]
[["B","B","B","B"],["B","B","B","B"],["B","B","B","B"],["B","B","B","B"]]
[["W","B","W","B"],["B","W","B","W"],["W","B","W","B"],["B","W","B","W"]]
[["B","W","W","W","B"],["W","W","W","W","W"],["W","W","B","W","W"],["W","W","W","W","W"],["B","W","W","W","B"]]
*/
