class Solution {
public:
    void bfs(int r, int c, vector<vector<char>> board){
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(unsigned int i=0; i<4; i++){
            int x = dx[i] + r;
            int y = dy[i] + c;

            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == 'O'){
                board[x][y] = 'A';
                bfs(x, y, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int r=0; r<board.size(); r++){
            if(board[r][0] == 'O'){
                board[r][0] = 'A';
                bfs(r, 0, board);
            }
            if(board[r][board[0].size()-1] == 'O'){
                board[r][board[0].size()-1] = 'A';
                bfs(r, board[0].size()-1, board);
            }
        }

        for(int c=0; c<board[0].size(); c++){
            if(board[0][c] == 'O'){
                board[0][c] = 'A';
                bfs(0, c, board);
            }
            if(board[board.size()-1][c] == 'O'){
                board[board.size()-1][c] = 'A';
                bfs(board.size()-1, c, board);
            }
        }

        for(unsigned int r=0; r<board.size(); r++){
            for(unsigned int c=0; c<board[0].size(); c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }

        for(unsigned int r=0; r<board.size(); r++){
            for(unsigned int c=0; c<board[0].size(); c++){
                if(board[r][c] == 'A'){
                    board[r][c] = 'O';
                }
            }
        }
    }
};


[["O","O","O","O","O","O","O","O","X","O","O","O","O","O","X","O","O","O","O","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","X","O","X","O","O","O","O","X","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","X","O"],["O","X","X","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","X","O","O","O","O","O","X","X","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","O"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","O","O","O","O","O","O","X","X","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","O","O","X","O","O","O","O","O","X"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","X","O","X","O","O"],["O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","X","O","O","O","X","O","O","X","O","O","X"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"]]



// [["X","X","X","X"],["X","O","O","O"],["X","X","O","X"],["X","O","X","X"]]
// [["X", "X", "X"],["X", "O", "X"],["X", "X", "X"]]
// [["O","X","X","O","X"],["X","O","O","X","O"],["X","O","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
// [["O","X","X","O","X"],["X","X","X","X","O"],["X","X","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
// [["O","X","O","O","O","X"],["O","O","X","X","X","O"],["X","X","X","X","X","O"],["O","O","O","O","X","X"],["X","X","O","O","X","O"],["O","O","X","X","X","X"]]
// [["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
