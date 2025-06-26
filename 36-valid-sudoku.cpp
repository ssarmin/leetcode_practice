//https://leetcode.com/problems/valid-sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            unordered_set<int> s_col;
            for(int c=0; c<board[i].size(); c++){//checking each column
                if(board[i][c] != '.'){
                    if(s_col.find(board[i][c]) == s_col.end()){
                        s_col.insert(board[i][c]);
                    }else{
                        return false;
                    }
                }
            }

            unordered_set<int> s_row;
            for(int r=0; r<board.size(); r++){//checking each row
                if(board[r][i] != '.'){
                    if(s_row.find(board[r][i]) == s_row.end()){
                        s_row.insert(board[r][i]);
                    }else{
                        return false;
                    }
                }
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                unordered_set<int> s;
                for(int r=0; r<3; r++){
                    for(int c=0; c<3; c++){
                        int row = i*3 + r;
                        int col = j*3 + c;
                        if(board[row][col] != '.'){
                            if(s.find(board[row][col]) == s.end()){
                                s.insert(board[row][col]);
                            }else{
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

//[[".",".","4",".",".",".","6","3","."],[".",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".","9","."],[".",".",".","5","6",".",".",".","."],["4",".","3",".",".",".",".",".","1"],[".",".",".","7",".",".",".",".","."],[".",".",".","5",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]]
//[[".","8","7","6","5","4","3","2","1"],["2",".",".",".",".",".",".",".","."],["3",".",".",".",".",".",".",".","."],["4",".",".",".",".",".",".",".","."],["5",".",".",".",".",".",".",".","."],["6",".",".",".",".",".",".",".","."],["7",".",".",".",".",".",".",".","."],["8",".",".",".",".",".",".",".","."],["9",".",".",".",".",".",".",".","."]]
