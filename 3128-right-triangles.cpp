//https://leetcode.com/problems/right-triangles/
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long res = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> m_row(row, 0);
        vector<int> m_col(col, 0);
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c]){
                    m_row[r]++;
                    m_col[c]++;
                }
            }
        }

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(grid[r][c]){
                    if(m_row[r] >= 2 && m_col[c] >= 2){
                        res += (m_row[r] - 1) * (m_col[c] - 1);
                    }
                }
            }
        }

        return res;
    }
};
