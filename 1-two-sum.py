class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}

        for index, value in enumerate(nums):
            if value in dic:
                return [index, dic[value]]
            else:
                dic[target-value] = index

        return []

"""
[-1000000000,-1000000000,0,-2]
-2
[3,2,4]
6
"""
