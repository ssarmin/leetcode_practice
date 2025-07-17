//https://leetcode.com/problems/max-number-of-k-sum-pairs
//optimized solution
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        for(auto n: nums){
            int other = k - n;
            if(m[other] > 0){
                count++;
                m[other]--;
            }else{
                m[n]++;
            }
        }
        return count;
    }
};

// [1,2,3,4]
// 5
// [3,1,3,4,3]
// 6
// [2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2]
// 3
// [3,1,5,1,1,1,1,1,2,2,3,2,2]
// 1
// [2,2,2,3,1,1,4,1]
// 3
// [29,26,81,70,75,4,48,38,22,10,51,62,17,50,7,7,24,61,54,44,30,29,66,83,6,45,24,49,42,31,10,6,88,48,34,10,54,56,80,41,19]
// 12
