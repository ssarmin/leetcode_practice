class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        prev = 0
        for index in range(len(nums)):
            if(val != nums[index]):
                nums[prev] = nums[index]
                prev = prev + 1
        return prev
        
