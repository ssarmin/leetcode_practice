//https://leetcode.com/problems/combination-sum
class Solution {
public:
    void dfs(vector<int> &v, int target, int index, vector<int> candidates, int sum, vector<vector<int>> &res){
        if(sum == target){
            res.push_back(v);
            return;
        }
        if(sum > target || index >= candidates.size() || candidates[index] > target){
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(candidates[i] > target){
                return;
            }
            v.push_back(candidates[i]);
            dfs(v, target, i, candidates, sum+candidates[i], res);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        dfs(v, target, 0, candidates, 0, res);
        return res;
    }
};

// [2,3,5,7,4]
// 7
// [2,3,5,7,4,6,8,9,10,11,12,13]
// 20
// [2,3,5,7,4,6]
// 25
// [2,3,5,7,4,6,8,9,10,11,12,13]
// 5
