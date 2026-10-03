//https://leetcode.com/problems/falling-squares/
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> height(positions.size(), 0);
        int max_height = 0;
        vector<int> temp(positions.size(), 0);
        for(int i=0; i<positions.size(); i++){
            int left = positions[i][0];
            int side = positions[i][1];
            int right = left + side;
            int temp_height_max = side;
            for(int j=0; j<i; j++){
                int prev_left = positions[j][0];
                int prev_side = positions[j][1];
                int prev_right = prev_side + prev_left;

                if((left <= prev_left && right > prev_left) || (left > prev_left && left < prev_right)){
                    temp_height_max = max(temp_height_max, temp[j] + side);
                }
            }
            temp[i] = max(temp[i], temp_height_max);
            max_height = max(max_height, temp_height_max);
            height[i] = max_height;
            
        }
        return height;
    }
};

/*
[[1,2],[2,3],[6,1],[2,4],[2,3]]
[[1,2],[2,3],[6,1],[2,4]]
[[1,2]]
[[9,6],[2,2],[2,6]]
*/
