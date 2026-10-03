//https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int res = 0;
        int m = pattern.size()+1;
        for(int i=0; i<nums.size()-m+1; i++){
            bool flag = true;
            for(int index = 0; index<pattern.size(); index++){
                if(pattern[index] == 1){
                    if(!(nums[i+index] < nums[i+index+1])){
                        flag = false;
                        break;
                    }
                }else if(pattern[index] == -1){
                    if(!(nums[i+index] > nums[i+index+1])){
                        flag = false;
                        break;
                    }
                }else{
                    if(nums[i+index] != nums[i+index+1]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)res++;
        }
        return res;
    }
};
