//https://leetcode.com/problems/sort-the-matrix-diagonally/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int r=0; r<row; r++){
            int dig_c = 0;
            int dig_r = r;
            vector<int> temp;
            int index = 0;
            while(dig_r < row && dig_c < col){
                temp.push_back(mat[dig_r++][dig_c++]);
            }
            sort(temp.begin(), temp.end());
            dig_r = r;
            dig_c = 0;
            while(dig_r < row && dig_c < col){
                mat[dig_r++][dig_c++] = temp[index++];
            }
        }

        for(int c=1; c<col; c++){
            int dig_c = c;
            int dig_r = 0;
            vector<int> temp;
            int index = 0;
            while(dig_r < row && dig_c < col){
                temp.push_back(mat[dig_r++][dig_c++]);
            }
            sort(temp.begin(), temp.end());
            dig_r = 0;
            dig_c = c;
            while(dig_r < row && dig_c < col){
                mat[dig_r++][dig_c++] = temp[index++];
            }
        }

        return mat;
    }
};

/*
[[3,3,1,1],[2,2,1,2],[1,1,1,2]]
*/
