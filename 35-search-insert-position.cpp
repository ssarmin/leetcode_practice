// https://leetcode.com/problems/search-insert-position
class Solution {
public:
    int bst(vector<int> nums, int start, int end, int target){
        if(start > end)
            return start;
        if(start == end){
            if(nums[start] >= target){
                return start;
            }else{
                return start+1;
            }
        }
        int mid = (end - start)/2 + start;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target){
            return bst(nums, start, mid-1, target);
        }else{
            return bst(nums, mid+1, end, target);
        }
        
    }
    int searchInsert(vector<int>& nums, int target) {
        return bst(nums, 0, nums.size()-1, target);
    }
};

// Time and space complexity:
// Time (`logn`)
// Space (`logn`) 

// We can optimize this code using an iterative approach

// Extra testcases:
// [1,3,5,6]
// 0
// [1,3,5,6,8]
// 7
// [1,3,5,6,8,9]
// 7
// [1]
// 1
// [1,3]
// 0
// [0,2,4,6,34,465]
// 5
// [0]
// 1
// [0]
// 0
// [1]
// 0
// [1]
// 2
