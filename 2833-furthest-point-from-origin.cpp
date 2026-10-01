//https://leetcode.com/problems/furthest-point-from-origin/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0;
        int r = 0;
        for(auto ch: moves){
            if(ch == 'L'){
                l++;
            }else if(ch == 'R'){
                r++;
            }
        }
        int dash = moves.size() - l - r;
        return dash + abs(l-r);
    }
};

//"__________________________________________________"
