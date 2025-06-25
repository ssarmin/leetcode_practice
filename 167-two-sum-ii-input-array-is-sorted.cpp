//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<numbers.size(); i++){
            if(m.find(numbers[i]) == m.end()){
                m[target-numbers[i]] = i;
            }else{
                return {m[numbers[i]]+1, i+1};
            }
        }
        return {0, 0};
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
  
// Extra testcases:
// [0,0,3,4]
// 0
// [-10,-8,-2,1,2,5,6]
// 0
