//https://leetcode.com/problems/spiral-matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_row = 0;
        int start_col = 0;
        int end_row = matrix.size();
        int end_col = matrix[0].size();

        vector<int> res;

        while(start_row < end_row && start_col < end_col){
            for(int c=start_col; c < end_col; c++){
                res.push_back(matrix[start_row][c]);
            }
            start_row++;

            for(int r=start_row; r < end_row; r++){
                res.push_back(matrix[r][end_col-1]);
            }
            end_col--;

            if(!(start_row < end_row && start_col < end_col))
                break;

            for(int c=end_col-1; c >= start_col; c--){
                res.push_back(matrix[end_row-1][c]);
            }
            end_row--;

            for(int r=end_row-1; r >= start_row; r--){
                res.push_back(matrix[r][start_col]);
            }
            start_col++;
        }

        return res;
    }
};

// [[6,9,7]]
// [[1,2,3,4]]
// [[1,2,3,4],[5,6,7,8]]
// [[1,2,3],[4,5,6],[7,8,9],[10,11,12],[13,14,15]]
// [[1]]
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
// [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15]]
// [[1,2,9,9,3,4,5,1],[1,2,9,9,1,4,1,1],[1,10,9,9,3,4,5,1],[1,21,9,9,3,4,5,1],[1,2,9,3,3,4,3,3],[1,2,19,9,13,4,15,1]]
// [[1,2,3,4,3],[5,6,7,8,1],[9,10,11,12,1]]
// [[1,2],[2,5]]
// [[1],[2]]
