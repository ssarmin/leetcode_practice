# https://leetcode.com/problems/remove-duplicates-from-sorted-array
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1
        prev = nums[0]
        
        for index in range(1, len(nums)):
            if(prev != nums[index]):
                nums[k] = nums[index]
                k = k+1
            prev = nums[index]
        
        return k
