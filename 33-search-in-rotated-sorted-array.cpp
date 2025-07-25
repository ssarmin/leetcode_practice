//https://leetcode.com/problems/search-in-rotated-sorted-array

//iterative solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end){
            int mid = (end - start)/2 + start;
            cout << start << " " << end << endl;
            if(nums[mid] == target){
                return mid;
            }else{
                //it's better to check with the 'end'
                //as for 2 values, start and mid would point to the same value
                if(nums[end] < nums[mid]){//left sorted
                    //as the left side sorted
                    //we are looking if the target within [start, mid] range
                    if(nums[start] <= target && target < nums[mid]){
                        end = mid-1;
                    }else{
                        start = mid+1;
                    }
                }else{//right sorted
                    //as the right side sorted
                    //we are looking if the target within [mid, end] range
                    if(nums[mid] < target && target <= nums[end]){
                        start = mid+1;
                    }else{
                        end = mid-1;
                    }
                }
            }
        }
        return -1;
    }
};

//recursive solution:
class Solution {
public:
    int search(vector<int>& nums, int target, int start, int end){
        if(start > end){
            return -1;
        }
        int mid = (end - start)/2 + start;
        if(nums[mid] == target){
            return mid;
        }else{
            if(nums[mid] > nums[end]){//left side sorted
                if(nums[mid] < target || target < nums[start]){
                    return search(nums, target, mid+1, end);
                }else{
                    return search(nums, target, start, mid-1);
                }
            }else{//right side sorted
                if(nums[mid] > target || target > nums[end]){
                    return search(nums, target, start, mid-1);
                }else{
                    return search(nums, target, mid+1, end);
                }
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
};

// Extra testcases:
// [5,1,3]
// 5
// [3,1]
// 1
// [1, 3, 5]
// 2
// [1, 3, 5]
// 1
// [1, 3, 5]
// 3
// [1, 3, 5]
// 5
// [3, 5, 1]
// 3
// [3, 5, 1]
// 1
// [3, 5, 1]
// 5
// [5, 1, 3]
// 3
// [5, 1, 3]
// 1
// [5, 1, 3]
// 5
// [3,1]
// 1
// [3,1]
// 3
// [3,1]
// 0
// [4,5,6,7,0,1,2]
// 5
// [5,1,2,3,4]
// 1
