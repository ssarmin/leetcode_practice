//https://leetcode.com/problems/insert-interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto v: intervals){
            if(res.empty()){
                res.push_back(v);
            }else{
                if(res.back()[0] <= v[0] && res.back()[1] >= v[0]){
                    res.back()[1] = max(res.back()[1], v[1]);
                }else{
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};

// []
// [2,5]
// [[3,5],[8,10]]
// [1,2]
// [[1,3],[6,9]]
// [11,12]
// [[1,3],[6,9]]
// [2,5]
// [[1,2],[3,5],[8,10]]
// [2,9]
// [[1,3],[6,9]]
// [2,7]
// [[1,3],[6,9]]
// [4,7]
// [[1,3],[6,9]]
// [3,6]
// [[2,4],[5,7],[8,10],[11,13]]
// [3,6]
// [[0,0],[2,4],[9,9]]
// [0,7]
// [[0,10],[14,14],[15,20]]
// [11,11]
// [[1,2],[5,6]]
// [2,5]
// [[1,2],[5,6]]
// [2,10]
// [[1,3],[4,4],[5,5]]
// [3,3]
// [[1,2],[3,5],[6,7],[8,10],[12,16]]
// [4,8]
