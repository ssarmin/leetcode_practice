//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        long long sum = 0;
        int left = 0;
        int right = 0;
        while(right < arr.size()){
            sum += arr[right];
            right++;

            if((right - left) == k){
                if(sum/k >= threshold)
                    count++;
                sum -= arr[left];
                left++;
            }
        }
        return count;
    }
};
