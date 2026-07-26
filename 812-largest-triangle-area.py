# //https://leetcode.com/problems/largest-triangle-area/description/
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        max_area = 0.0
        for i_1 in range(0, len(points)):
            for i_2 in range(i_1+1, len(points)):
                for i_3 in range(i_2+1, len(points)):
                    x1 = points[i_1][0]
                    y1 = points[i_1][1]

                    x2 = points[i_2][0]
                    y2 = points[i_2][1]

                    x3 = points[i_3][0]
                    y3 = points[i_3][1]

                    area = 1/2 * abs(x1*(y2- y3) + x2*(y3- y1) + x3*(y1- y2))

                    max_area = max(max_area, area)
        
        return max_area
