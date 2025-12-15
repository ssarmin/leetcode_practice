//https://leetcode.com/problems/missing-number-in-arithmetic-progression
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int min_val = arr[0];
        int max_val = arr[0];
        for(auto a: arr){
            min_val = min(min_val, a);
            max_val = max(max_val, a);
        }
        unordered_set<int> s(arr.begin(), arr.end());
        int diff = (max_val - min_val)/arr.size();
        for(int i=min_val+diff; i < max_val; i = i + diff){
            if(s.count(i))continue;
            return i;
        }
        return min_val;
    }
};
//[0,0,0,0,0]
