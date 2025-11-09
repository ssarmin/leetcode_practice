//https://leetcode.com/problems/merge-triplets-to-form-target-triplet
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = 0, second = 0, third = 0;
        for(int i=0; i<triplets.size(); i++){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;
            if(target[0] == triplets[i][0])
                first++;
            if(target[1] == triplets[i][1])
                second++;
            if(target[2] == triplets[i][2])
                third++;
        }
        if(first && second && third)
            return true;
        return false;
    }
};
// [[3,1,7],[1,5,10]]
// [3,5,7]
// [[3, 1, 2], [1, 4, 3], [2, 2, 5]]
// [3, 4, 5]
// [[1,1,5],[1,7,1],[2,1,1]]
// [2,7,5]
