//https://leetcode.com/problems/max-consecutive-ones-iii
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int ones = 0;
        int maxOnes = 0;
        int left = 0;
        int right = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                zeros++;
                while(left < nums.size() && zeros > k){
                    if(nums[left] == 0){
                        zeros--;
                    }else{
                        ones--;
                    }
                    left++;
                }
            }else{
                ones++;
            }
            maxOnes = max(ones+zeros, maxOnes);
            right++;
        }

        return maxOnes;
    }
};


//time complexity: O(n)
//space complexity: O(1)

// [0,0,0,0]
// 0
// [0,0,1,1,1,0,0]
// 0
// [0,0,1,1]
// 1
// [0,0,0,1]
// 4
// [0,0,1,1,1,0,0]
// 0
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
// 3
// [0,0,0,1]
// 4
// [0,0,1,1]
// 1
// [0,0,1,1,1,0,0] 
// 0 
// [0,0,0,0]
// 0
// [1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,1,1]
// 8
// [1,1,1,0,0,0,1,1,1,1,0]
// 2
