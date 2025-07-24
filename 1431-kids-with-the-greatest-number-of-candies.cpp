//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxVal = candies[0];
        for(auto c: candies){
            maxVal = max(maxVal, c);
        }
        vector<bool> res;
        for(auto c: candies){
            if(c + extraCandies >= maxVal){
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};
