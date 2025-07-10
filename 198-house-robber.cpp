//https://leetcode.com/problems/house-robber

// The robber's goal is to steal the maximum amount possible up to any given house. So, in our logic, when we are at house i, we calculate the maximum amount that can be robbed up to that point.

// If there's only one house, the maximum amount is simply the value of that house.

// With two houses, we can't rob both, so the result is the maximum of the two.

// For the third house (index i = 2), we have two choices:

// Rob the current house and add it to the amount from house i - 2,

// Or skip the current house and take the amount from house i - 1.
// We choose the maximum of these two.

// For each subsequent house, we apply the same logic.

// At every index, we store the maximum amount that can be robbed up to that house, ensuring our solution is built progressively and optimally.

    
// optimized solution
//Bottom-up solution
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
            
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int val1 = nums[0];
        int val2 = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            int val = max(val2, val1+nums[i]);
            val1 = val2;
            val2 = val;
        }

        return val2;
    }
};
// Time complexity: O(n)
// Space complexity: O(1)


//Bottom up with table
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> v(nums.size(), 0);

        v[0] = nums[0];
        v[1] = nums[1];

        for(int i = 2; i < nums.size(); i++){
            if(i == 2)
                v[i] = nums[i] + v[i-2];
            else
                v[i] = nums[i] + max(v[i-2], v[i-3]);
        }

        return max(v[nums.size()-1], v[nums.size()-2]);
    }
};
// Time complexity: O(n)
// Space complexity: O(n)



// Top-down approach with memo
class Solution {
public:
    unordered_map<int, int> m;
    int dp(int index, vector<int> &nums){
        if(m.find(index) != m.end()){
            return m[index];
        }
        if(index == 0){
            m[index] = nums[index];
        }else if(index == 1){
            m[index] = max(nums[index], nums[index-1]);
        }else{
            m[index] = max((nums[index] + dp(index-2, nums)), dp(index-1, nums));
        }
        return m[index];
    }
    int rob(vector<int>& nums) {
        return dp(nums.size()-1, nums);
    }
};


// Extra testcases:
// [2,7,9,3,0,21,2,3,11]
// [2,1,1,2]
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
// [8, 9, 9, 4, 10, 5, 6, 9, 7, 9]
// [1,1,1]
