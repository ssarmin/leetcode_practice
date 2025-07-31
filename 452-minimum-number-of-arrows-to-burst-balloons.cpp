//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> res;
        for(auto v: points){
            if(res.empty()){
                res.push_back(v);
            }else{
                if(res.back()[0] <= v[0] && res.back()[1] >= v[0]){
                    res.back()[0] = max(res.back()[0], v[0]);
                    res.back()[1] = min(res.back()[1], v[1]);
                }else{
                    res.push_back(v);
                }
            }
        }
        return res.size();
    }
};

// [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
// [[1, 2], [2, 3], [3, 4], [4, 5], [5, 6]]
// [[0, 10], [20, 30], [40, 50], [60, 70]]
// [[-10, -5], [-7, 0], [2, 5], [7, 10]]
// [[100, 200], [150, 250], [180, 220], [210, 230]]
// [[-50, -40], [-30, -20], [-10, 0], [10, 20], [30, 40]]
// [[500, 510], [520, 530], [540, 550], [560, 570], [580, 590]]
// [[0, 1], [1, 2], [2, 3], [3, 4], [4, 5]]
// [[10, 20], [30, 40], [50, 60], [70, 80], [90, 100]]
// [[1,2],[2,3],[3,4],[4,5]]
// [[10,16],[2,8],[1,6],[7,12]]
// [[1,2],[3,4],[5,6],[7,8]]
// [[1,2]]
// [[2,3],[2,3]]
