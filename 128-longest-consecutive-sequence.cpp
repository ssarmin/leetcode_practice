// https://leetcode.com/problems/longest-consecutive-sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        map<int, int> m;
        for(auto n: nums){
            m[n]++;
        }
        int count, maxCount, prev;
        for(auto it = m.begin(); it != m.end(); it++){
            if(it == m.begin()){
                count = 1;
                maxCount = 1;
                prev = m.begin()->first;
                continue;
            }
            if(prev+1 == it->first){
                count++;
            }else{
                maxCount = max(maxCount, count);
                count = 1;
            }
            prev = it->first;
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)

// [0,3,7,2,5,8,4,6,0,1]
// [0]
// [0,0]
// []
// [1,2,0,1]
// [-8,-4,9,9,4,6,1,-4,-1,6,8]
// [1000000000,-1000000000]
