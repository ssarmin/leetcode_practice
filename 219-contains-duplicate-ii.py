class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic = {}
        for index, value in enumerate(nums):
            if value in dic:
                if abs(index - dic[value]) <= k:
                    return True
            dic[value] = index
        
        return False

"""
[1,0,1,1]
1
[99, 99]
2
[99, 99]
1
[1, 5, 1, 0]
2
"""
