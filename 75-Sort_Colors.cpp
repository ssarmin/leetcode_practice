//https://leetcode.com/problems/sort-colors/description/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        for(auto a: nums){
            if(a == 0)
                zero++;
            else if(a == 1)
                one++;
        }
        int i=0;
        for(; i<zero; i++){
            nums[i] = 0;
        }

        for(; i<zero+one; i++){
            nums[i] = 1;
        }
        
        for(; i<nums.size(); i++){
            nums[i] = 2;
        }
    }
};

//Extra testcase:
// [2, 0, 1, 2]
