class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return
        row, col = len(board), len(board[0])
        q = deque()
        for r in range(row):
            if board[r][0] == 'O':
                board[r][0] = '1'
                q.append((r,0))
            if board[r][col-1] == 'O':
                board[r][col-1] = '1'
                q.append((r,col-1))

        for c in range(1, col-1):
            if board[0][c] == 'O':
                board[0][c] = '1'
                q.append((0,c))
            if board[row-1][c] == 'O':
                board[row-1][c] = '1'
                q.append((row-1,c))
        
        dirc = {(0, 1), (0, -1), (1,0), (-1, 0)}
        while q:
            r, c = q.popleft()
            for (x, y) in dirc:
                x += r
                y += c
                if x >= 0 and y >= 0 and x < row and y < col and board[x][y] == 'O':
                    board[x][y] = '1'
                    q.append((x,y))

        for r in range(row):
            for c in range(col):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                if board[r][c] == '1':
                    board[r][c] = 'O'

"""
[["X","O","X"],["O","X","O"],["X","O","X"]]
[["X","X","X","X"],["X","O","O","O"],["X","X","O","X"],["X","O","X","X"]]
[["X", "X", "X"],["X", "O", "X"],["X", "X", "X"]]
[["O","X","X","O","X"],["X","O","O","X","O"],["X","O","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
[["O","X","X","O","X"],["X","X","X","X","O"],["X","X","X","O","X"],["O","X","O","O","O"],["X","X","O","X","O"]]
[["O","X","O","O","O","X"],["O","O","X","X","X","O"],["X","X","X","X","X","O"],["O","O","O","O","X","X"],["X","X","O","O","X","O"],["O","O","X","X","X","X"]]
[["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]]
[["O","O","O","O","O","O","O","O","X","O","O","O","O","O","X","O","O","O","O","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","X","O","X","O","O","O","O","X","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","X","O"],["O","X","X","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","X","O","O","O","O","O","X","X","O"],["O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","X","O"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","O","O"],["X","O","O","O","O","O","O","O","O","X","X","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","O","O","O","X","O","O","O","O","O","O","O","O"],["O","O","O","O","X","O","O","O","O","O","O","O","O","X","O","O","O","O","O","X"],["O","O","O","O","O","X","O","O","O","O","O","O","O","O","O","X","O","X","O","O"],["O","X","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"],["O","O","O","O","O","O","O","O","X","X","O","O","O","X","O","O","X","O","O","X"],["O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O","O"]]
"""
