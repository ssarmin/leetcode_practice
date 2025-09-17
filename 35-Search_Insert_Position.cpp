//https://leetcode.com/problems/search-insert-position/description/
class Solution {
public:
    void search(vector<int> nums, int start, int end, int target, int &index){
        if(start > end)
            return;
        int mid = (end + start)/2;
        if(nums[mid] == target){
            index = mid;
            return;
        }else if(nums[mid] > target){
            index = mid;
            search(nums, start, mid-1, target, index);
        }else{
            index = mid+1;
            search(nums, mid+1, end, target, index);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        search(nums, 0, nums.size()-1, target, index);
        return index;
    }
};

//Time complexity: O(nlogn)

// [1,3,5,6]
// 0
// [1,3,5,6]
// 2
// [1,3]
// 0
// [1]
// 1
