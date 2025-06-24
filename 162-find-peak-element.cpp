//https://leetcode.com/problems/find-peak-element
// optimized code:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;

        while(start < end){
            int mid = (end - start)/2 + start;
            if(nums[mid] < nums[mid+1]){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return start;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        if(nums.size() == 2){
            if(nums[0] > nums[1])
                return 0;
            return 1;
        }
        int start = 0;
        int end = nums.size()-1;
        while(start <= end){
            if(end == start)
                return end;
            int mid = (end - start)/2 + start;
            if(mid > 0 && mid < nums.size()-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;
                }else if(nums[mid] < nums[mid+1]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }else if(mid == 0 && mid < nums.size()-1){
                if(nums[mid] > nums[mid+1])
                    return mid;
                return mid+1;
            }else{
                if(nums[mid-1] < nums[mid])
                    return mid;
                return mid-1;
            }
        }
        return 0;
    }
};

// Extra testcases:
// [1,2,3]
// [1,20,1,3,4,5,6,7,8,9,10]
// [7,8,9,1,2,3,4,5,6]
// [1,3,5,7]
// [6,10,9,8,7,6,3,5,6,7,8,9,10,11,12]
// [6,5,4,3,2,3,2]
// [3,4,3,2,1]
// [5,4,3,4,5]
// [1,2,1,3,4,5,0]
// [1]
// [1,2]
// [2,1]
// [6,5,4,3,2,3,2]
// [1,2,1,3,5,6,4]
// [3,2,1]
// [-2147483648]
// [1,2,3,1]
// [1,2,1,3,4,5,0]
// [1,2,1,3,5,6,4]
// [1,2,3,1,100,200,300,400,500,600,700]
// [2,25,10,5,25,3]
