//https://leetcode.com/problems/koko-eating-bananas
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int end = 1;
        for(auto p: piles){
            end = max(end, p);
        }
        int start = 1;
        
        while(start <= end){
            int mid = (end - start)/2 + start;
            long hour = 0;
            for(auto p: piles){
                hour += ceil(1.0*p/(mid*1.0));
            }
            if(hour <= h){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};
// [805306368,805306368,805306368]
// 1000000000
// [312884470]
// 312884469
