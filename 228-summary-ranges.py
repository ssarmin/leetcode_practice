class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        res = []
        if(len(nums) == 0):
            return res
        p = [str(nums[0]), None]
        for i in range(1, len(nums)):
            if(nums[i] - 1 == nums[i-1]):
                p[1] = str(nums[i])
            else:
                if(p[1] is None):
                    res.append(p[0])
                else:
                    res.append(f"{p[0]}->{p[1]}")
                p = [str(nums[i]), None]

        if(p[1] is None):
            res.append(p[0])
        else:
            res.append(f"{p[0]}->{p[1]}")
        
        return res
