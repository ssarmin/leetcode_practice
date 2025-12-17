//https://leetcode.com/problems/design-tic-tac-toe
class TicTacToe {
public:
    unordered_map<int, unordered_map<int, unordered_set<int>>> m_row;//person, row, col
    unordered_map<int, unordered_map<int, unordered_set<int>>> m_col;//person, row, col
    int N;
    TicTacToe(int n) {
        N = n;
    }
    
    int move(int row, int col, int player) {
        m_row[player][row].insert(col);
        m_col[player][col].insert(row);
        if(m_row[player][row].size() == N || m_col[player][col].size() == N){
            return player;
        }
        if(row == col){
            int count = 0;
            for(int i=0; i<N; i++){
                if(m_row.count(player) && m_row[player].count(i) && m_row[player][i].count(i) && m_col.count(player) && m_col[player].count(i) && m_col[player][i].count(i)){
                    count++;
                }
            }
            if(count == N){
                return player;
            }
        }
        int count = 0;
        for(int i=0; i<N; i++){
            int r = N-1;
            if(m_row.count(player) && m_row[player].count(r-i) && m_row[player][r-i].count(i) && m_col.count(player) && m_col[player].count(i) && m_col[player][i].count(r-i)){
                count++;
            }
        }
        if(count == N){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

/*
["TicTacToe","move","move","move"]
[[2],[0,1,1],[1,1,2],[1,0,1]]
["TicTacToe","move","move","move"]
[[2],[0,0,2],[0,1,1],[1,1,2]]
["TicTacToe","move","move","move","move","move","move","move"]
[[3],[0,0,1],[0,2,2],[2,2,1],[1,1,2],[2,0,1],[1,0,2],[2,1,1]]
["TicTacToe","move","move","move","move","move"] 
[[3],[0,0,1],[0,1,2],[1,1,1],[0,2,2],[2,2,1]]
["TicTacToe","move","move","move","move","move"] 
[[3],[0,0,1],[1,0,2],[0,1,1],[1,1,2],[0,2,1]]
["TicTacToe","move","move","move","move","move"] 
[[3],[0,2,1],[1,1,2],[1,2,1],[2,0,2],[2,2,1]]
["TicTacToe","move","move","move","move","move"] 
[[4],[0,0,1],[1,1,2],[0,1,1],[2,2,2],[0,2,1]]
["TicTacToe","move","move","move","move","move","move","move"] 
[[4],[3,0,1],[0,0,2],[2,1,1],[1,1,2],[1,2,1],[2,2,2],[0,3,1]]
["TicTacToe","move","move","move","move","move","move","move","move","move"] 
[[5],[0,0,1],[1,0,2],[0,1,1],[1,1,2],[0,2,1],[1,2,2],[0,3,1],[1,3,2],[0,4,1]]
["TicTacToe","move","move","move","move","move","move","move"] 
[[5],[0,4,2],[1,3,1],[1,4,2],[2,2,1],[2,4,2],[3,1,1],[3,4,2]]
["TicTacToe","move","move","move","move","move","move","move","move","move"]
[[3],[0,0,1],[0,2,2],[1,1,1],[2,2,2],[1,2,1],[1,0,2],[0,1,1],[2,1,2],[2,0,1]]
*/
