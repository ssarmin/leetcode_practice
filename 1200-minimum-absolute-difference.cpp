//https://leetcode.com/problems/minimum-absolute-difference
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int val = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            val = min(val, abs(arr[i] - arr[i-1]));
        }
        vector<vector<int>> res;
        for(int i=1; i<arr.size(); i++){
            if(abs(arr[i] - arr[i-1]) == val){
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};
