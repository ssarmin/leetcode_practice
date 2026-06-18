class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_water = 0
        while (left < right):
            water = 0
            if(height[left] < height[right]):
                water = height[left]
                water = water * (right - left)
                left = left + 1
            else:
                water = height[right]
                water = water * (right - left)
                right = right - 1
            
            if(max_water < water):
                max_water = water

        return max_water
