//https://leetcode.com/contest/biweekly-contest-161/problems/split-array-by-prime-indices
class Solution {
public:
    bool isPrime(int n){
        if(n%2 == 0 && n != 2)
            return false;
        for(int i=2; i*i <= n; i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long val = 0;
        for(int i=0; i<nums.size(); i++){
            if(i < 2){
                val -= nums[i];
            }else if(isPrime(i)){
                val += nums[i];
            }else{
                val -= nums[i];
            }
        }
        return llabs(val);
    }
};

// [175868717,841457609,-948571070,-747264172]
// [632920512,804538926,458130111,807392836,533751157,983581186]
