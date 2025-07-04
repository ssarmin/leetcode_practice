//https://leetcode.com/problems/kth-largest-element-in-an-array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k > 1){
            k--;
            pq.pop();
        }
        return pq.top();
    }
};
// [2,1]
// 1
// [-1,-1]
// 1
// [3,2,3,1,2,4,5,5,6]
// 4
// [7,6,5,4,3,2,1]
// 3
