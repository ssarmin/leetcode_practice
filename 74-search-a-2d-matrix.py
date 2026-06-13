class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        start, end = 0, row*col-1

        while start <= end:
            mid = (start+end)//2
            r = mid//col
            c = mid%col
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] > target:
                end = mid - 1
            else:
                start = mid + 1
        
        return False
