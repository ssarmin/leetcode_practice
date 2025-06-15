//https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    bool isValid(vector<vector<char>> board, int r, int c){
        if(r >= 0 && c >= 0 && r < board.size() && c < board[0].size()){
            return true;
        }

        return false;
    }
    void explore(vector<vector<char>>& board, int r, int c){
        board[r][c] = 'N';
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i=0; i<4; i++){
            int x = r + dx[i];
            int y = c + dy[i];
            if(isValid(board, x, y) && board[x][y] == 'O'){
                explore(board, x, y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int r = 0; r < row; r++){
            if(board[r][0] == 'O')
                explore(board, r, 0);

            if(board[r][col-1] == 'O')
                explore(board, r, col-1);
        }
        for(int c = 0; c < col; c++){
            if(board[0][c] == 'O')
                explore(board, 0, c);

            if(board[row-1][c] == 'O')
                explore(board, row-1, c);
        }

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == 'N'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};

//Extra testcases:
// [["X","X","X","X"],["X","O","O","O"],["X","X","O","X"],["X","O","X","X"]]
// [["X", "X", "X"],["X", "O", "X"],["X", "X", "X"]]
// [["O","X","X","O","X"],["X","O","O","X","O"],["X","O","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
// [["O","X","X","O","X"],["X","X","X","X","O"],["X","X","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
// [["O","X","O","O","O","X"],["O","O","X","X","X","O"],["X","X","X","X","X","O"],["O","O","O","O","X","X"],["X","X","O","O","X","O"],["O","O","X","X","X","X"]]
// [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
//[["O","O","O","O","O","O","O","O","X","O","O","O","O","O","X","O","O","O","O","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","X","O","X","O","O","O","O","X","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","X","O"],["O","X","X","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","X","O","O","O","O","O","X","X","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","O"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","O","O","O","O","O","O","X","X","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","O","O","X","O","O","O","O","O","X"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","X","O","X","O","O"],["O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","X","O","O","O","X","O","O","X","O","O","X"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"]]
