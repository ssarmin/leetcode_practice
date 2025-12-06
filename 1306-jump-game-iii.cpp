https://leetcode.com/problems/jump-game-iii
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visit(arr.size(), false);
        queue<int> q;
        q.push(start);
        visit[start] = true;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index] == 0)
                return true;
            int right = index + arr[index];
            int left = index - arr[index];
            if(right < arr.size() && !visit[right]){
                q.push(right);
                visit[right] = true;
            }
            if(left >= 0 && !visit[left]){
                q.push(left);
                visit[left] = true;
            }
        }
        return false;
    }
};
/*
[3,0,2,1,2]
2
[4,2,3,0,3,1,2]
0
[3,0,2,1,2] 
2
*/
