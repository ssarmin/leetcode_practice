//https://leetcode.com/problems/find-the-highest-altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int prev = 0;
        for(auto a: gain){
            prev = prev+a;
            maxAlt = max(maxAlt, prev);
        }

        return maxAlt;
    }
};
