// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int index, int r, int c){
        if(index == word.size()-1)
            return true;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        
        index++;
        char temp = board[r][c];
        board[r][c] = '*';
        for(int i=0; i<4; i++){
            int x = r + dx[i];
            int y = c + dy[i];

            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() && board[x][y] == word[index]){
                if(dfs(board, word, index, x, y))
                    return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[r].size(); c++){
                if(word[0] == board[r][c]){
                    if(dfs(board, word, 0, r, c))
                        return true;
                }
            }
        }

        return false;
    }
};

// Extra testcases:
// [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
// "ABCESEEEFS"
// [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
// "ABCEFSADEESE"

// [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
// "AAAAAAAAAAAAAAB"
// [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","B"],["A","A","A","A","B","A"]]
// "AAAAAAAAAAAAABB"
// [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
// "AAAAAAAAAAAAAAB"
// [["a"],["a"]]
// "A"
// [["C","A","A"],["A","A","A"],["B","C","D"]]
// "AAB"
// [["a","b"],["c","d"]]
// "abcd"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCCED"
// [["a"]]
// "a"
