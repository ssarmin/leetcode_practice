// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150
// Recursive solution:

class Solution {
public:
    bool bst(vector<vector<int>> matrix, int target, int r_start, int r_end, int c_start, int c_end){
        if(r_start <= r_end && c_start <= c_end){
            int r_mid = (r_end - r_start)/2 + r_start;
            int c_mid = (c_end - c_start)/2 + c_start;

            if(matrix[r_mid][c_mid] == target)
                return true;
            if(matrix[r_mid][c_mid] > target){
                return bst(matrix, target, r_start, r_mid-1, c_start, c_end) || bst(matrix, target, r_mid, r_mid, c_start, c_mid-1);
            }else{
                return bst(matrix, target, r_mid+1, r_end, c_start, c_end) || bst(matrix, target, r_mid, r_mid, c_mid+1, c_end);
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r_end = matrix.size()-1;
        int c_end = matrix[0].size()-1;
        int r_start = 0;
        int c_start = 0;

        return bst(matrix, target, r_start, r_end, c_start, c_end);
    }
};
// Time complexity: O(Row+Col)



// Iterative solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int r = row-1;
        int c = 0;

        while(r >= 0 && r < row && c >= 0 && c < col){
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] > target)
                r--;
            else
                c++;
        }

        return false;
    }
};
