class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = []
        left.append(1)

        for index in range(0, len(nums)-1):
            left.append(left[-1]*nums[index])
        
        right = []
        right.append(1)
        nums = nums[::-1]
        for index in range(0, len(nums)-1):
            right.append(right[-1]*nums[index])
        
        right = right[::-1]

        for i in range(0, len(nums)):
            left[i] *= right[i]
        
        return left
"""
[1,2,3,2,4,6,2,1,5,3,0,20, 2,0, 4]
[-1,1,0,3,5,6,3,2,5,7,-3,3]
"""
