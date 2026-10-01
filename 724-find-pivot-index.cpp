//https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        int len = nums.size();
        for(int i=1; i<nums.size(); i++){
            left[i] = left[i-1] + nums[i-1];
        }
        for(int i=len-2; i>=0; i--){
            right[i] = right[i+1] + nums[i+1];
        }
        for(int i=0; i<nums.size(); i++){
            if(left[i] == right[i])
                return i;
        }
        return -1;
    }
};

// ----------------------------------------------

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int start = 0;
        int end = nums.size()-1;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left_total = 0;
        int right_total = total;
        while(start < nums.size()){
            right_total -= nums[start];
            if(left_total == right_total){
                return start;
            }
            left_total += nums[start];
            start++;
        }
        return -1;
    }
};


/*
[-1,-1,-1,0,1,1]
[-1,-1,-1,-1,-1,-1]
[1,-1,2]
[2,3,-1,8,4]
[1,-1,4]
[2,5]
[-1,-1,0,1,1,0]
[-1,-1,0,0,-1,-1]
[-1,-1,-1,-1,0,1]
[-1,-1,-1,1,1,1]
*/
