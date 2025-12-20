//https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> s;
        int index = -1;
        for(int i=nums.size()-1; i>=0; i--){
            if(s.count(nums[i])){
                index = i;
                break;
            }
            s.insert(nums[i]);
        }
        if(index == -1)
            return 0;
        if((index+1)%3 == 0){
            return (index+1)/3;
        }
        else return 1 + (index+1)/3;
    }
};
