class Solution:
    def traverse(self, grid: List[List[str]], r, c, row, col):
        q = deque([(r,c)])
        dx = (0, 0, 1, -1)
        dy = (1, -1, 0, 0)
        while q:
            r, c = q.popleft()

            for i in range(0, 4):
                x = r + dx[i]
                y = c + dy[i]
                if x >= 0 and y >= 0 and x < row and y < col and grid[x][y] == '1':
                    grid[x][y] = '0'
                    q.append((x,y))

    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        row = len(grid)
        col = len(grid[0])

        for r in range(row):
            for c in range(col):
                if grid[r][c] == '1':
                    res += 1
                    grid[r][c] = '0'
                    self.traverse(grid, r, c, row, col)
        
        return res
        
