//https://leetcode.com/problems/combination-sum-ii
class Solution {
public:
    void dfs(set<vector<int>> &res, vector<int> &candidates, vector<int> &v, int target, int index, int sum, set<vector<int>> &s){
        if(s.count(v)){
            return;
        }
        if(sum == target){
            res.insert(v);
            return;
        }
        if(sum > target || index >= candidates.size() || candidates[index] > target){
            return;
        }
        s.insert(v);
        for(int i=index; i<candidates.size(); i++){
            v.push_back(candidates[i]);
            dfs(res, candidates, v, target, i+1, sum+candidates[i], s);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> s;
        set<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(res, candidates, v, target, 0, 0, s);
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
};

// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
// 30
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,33,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,44,4,4,4,5,5,5,5,5,5,5,5,5,5,5,49,5,5,5,5,6,6,6,6]
// 29
// [14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12]
// 27
// [1]
// 1
// [1,1,1,3]
// 3
// [1,1,2,2]
// 3
// [1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1]
// 10
// [10,1,2,7,6,1,5]
// 8
