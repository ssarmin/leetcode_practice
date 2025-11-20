// https://leetcode.com/problems/jump-game-ii
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> visit(nums.size(), INT_MAX);

        visit[0] = 0;
        for(int i=0; i<nums.size(); i++){
            for(int k=1; k<=nums[i] && i + k < nums.size(); k++){
                visit[i+k] = min(visit[i+k], visit[i]+1);
            }
        }
        return visit[nums.size()-1];
    }
};

// extra testcases:
/*
[2,3,1,1,4,0,5,3,3,1,5,2,6,7,2,0,2,4,6,2]
[3,2,1,4,0,3,6,3,6,3,2,5,2,0,0,0,1,2,45]
[2,3,0,0,4]
[2,5,0,0]
[1,1,2,2,0,1,1]
[2,3,0,1,4]
*/
