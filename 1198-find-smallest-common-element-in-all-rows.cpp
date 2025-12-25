//https://leetcode.com/problems/find-smallest-common-element-in-all-rows
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_set<int> row_set(mat[0].begin(), mat[0].end());
        for(int r=1; r<row; r++){
            unordered_set<int> row_r(mat[r].begin(), mat[r].end());
            unordered_set<int> temp;
            for(auto a: row_set){
                if(row_r.count(a))
                    temp.insert(a);
            }
            row_set.clear();
            row_set = temp;
        }
        if(row_set.size() == 0)
            return -1;
        int min_val = INT_MAX;
        for(auto a: row_set){
            min_val = min(min_val, a);
        }
        return min_val;
    }
};
