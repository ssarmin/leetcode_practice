class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 1:
            return 0
        if l == 2:
            return 0 if nums[0] > nums[1] else 1
        start = 0
        end = l - 1
        index = end
        while start <= end:
            mid = (end + start)//2
            if mid != 0 and mid != l-1:
                if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
                    return mid
                if nums[mid+1] > nums[mid-1]:
                    start = mid+1
                else:
                    end = mid-1
            elif mid > 0:
                if nums[mid] > nums[mid-1]:
                    return mid
                else:
                    return mid-1
            else:
                if nums[mid] > nums[mid+1]:
                    return mid
                else:
                    return mid+1

"""
[1,2,3]
[1,20,1,3,4,5,6,7,8,9,10]
[7,8,9,1,2,3,4,5,6]
[1,3,5,7]
[6,10,9,8,7,6,3,5,6,7,8,9,10,11,12]
[6,5,4,3,2,3,2]
[3,4,3,2,1]
[5,4,3,4,5]
[1,2,1,3,4,5,0]
[1]
[1,2]
[2,1]
[6,5,4,3,2,3,2]
[1,2,1,3,5,6,4]
[3,2,1]
[-2147483648]
[1,2,3,1]
[1,2,1,3,4,5,0]
[1,2,1,3,5,6,4]
[1,2,3,1,100,200,300,400,500,600,700]
[2,25,10,5,25,3]
"""
