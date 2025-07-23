//https://leetcode.com/problems/find-the-difference-of-two-arrays
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s_nums1(nums1.begin(), nums1.end());
        unordered_set<int> s_nums2(nums2.begin(), nums2.end());

        vector<vector<int>> res;
        res.emplace_back();
        for(auto val: s_nums1){
            if(!s_nums2.count(val))
                res.back().push_back(val);
        }

        res.emplace_back();
        for(auto val: s_nums2){
            if(!s_nums1.count(val))
                res.back().push_back(val);
        }

        return res;
    }
};

// [-80,-15,-81,-28,-61,63,14,-45,-35,-10]
// [-1,-40,-44,41,10,-43,69,10,2]
// [80,5,-20,33,26,29]
// [-69,0,-36,52,-84,-34,-67,-100,80]
// [26,48,-78,-25,42,-8,94,-68,26]
// [61,-17]
