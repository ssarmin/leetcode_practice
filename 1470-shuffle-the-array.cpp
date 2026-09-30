//https://leetcode.com/problems/shuffle-the-array/
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        res.resize(2*n);
        int index = 0;
        for(int i=0; i<n; i++){
            res[index++] = nums[i];
            res[index++] = nums[n + i];
        }
        return res;
    }
};
