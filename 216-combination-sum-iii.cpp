//https://leetcode.com/problems/combination-sum-iii
class Solution {
public:
    void helper(int numbers_left, int target, vector<bool> &visit, vector<vector<int>> &res, vector<int> v, int index){
        if(numbers_left == 0 && target == 0){
            res.push_back(v);
            return;
        }
        if(target < index || numbers_left < 0)
            return;
        for(int i = index; i<10; i++){
            if(!visit[i]){
                visit[i] = true;
                v.push_back(i);
                helper(numbers_left-1, target-i, visit, res, v ,i+1);
                v.pop_back();
                visit[i] = false;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> visit(10, false);
        vector<vector<int>> res;
        for(int i=1; i<10; i++){
            visit[i] = true;
            helper(k-1, n-i, visit, res, {i} ,i+1);
            visit[i] = false;
        }
        return res;
    }
};
/*
9
60
5
60
2
60
9
1
2
1
*/
