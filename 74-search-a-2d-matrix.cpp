// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;
        while(start <= end){
            int mid = (end - start)/2 + start;
            int r = mid/col;
            int c = mid%col;
            if(matrix[r][c] == target)
                return true;
            if(matrix[r][c] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return false;
    }
};
// Time complexity: O(log(m*n))
// This approach won't work if it's not sorted globally (only each row is sorted, but, no relation with the previous row's last element)



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
// Time complexity: O(M+N)


// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
// 3
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
// 13
// [[1],[3],[5]]
// 0
// [[1],[3],[5]]
// 1
// [[1],[3],[5]]
// 5
// [[1, 3]]
// 3
// [[1, 3]]
// 2
// [[1]]
// 1
// [[1],[3],[5]]
// 3
// [[1], [3], [5], [7], [9], [11], [13], [15], [17], [19], [21], [23], [25], [27], [29], [31], [33], [35], [37], [39], [41], [43], [45], [47], [49], [51], [53], [55], [57], [59], [61], [63], [65], [67], [69], [71], [73], [75], [77], [79], [81], [83], [85], [87], [89], [91], [93], [95], [97], [99]]
// 3
// [[1],[3],[5],[6]]
// 3
// [[1, 3]]
// 2
