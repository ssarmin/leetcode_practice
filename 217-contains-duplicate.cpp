//https://leetcode.com/problems/contains-duplicate
// solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        s.reserve(nums.size());//prevents memeory reallocation
        for(auto n: nums){
            if(s.count(n))
                return true;
            s.insert(n);
        }
        return false;
    }
};
/*
solution 1 is better than solution 2, as solution 2 is creating the whole set before checking. in solution 1 offers early exit.

solution 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

*/
/*
[7,10,5,5,6,6,4,10,5,4,9,4,9,6,5,9,6,3,6,5,6,7,7,4,9,9,10,5,8,1,8,3,2,7,5,10,1,8,5,8,4,3,6,4,9,4,2,8,3,2,2,1,5,6,3,2,6,1,8,6,2,9,1,4,5,10,8,5,10,5,10,1,4,8,3,6,4,10,9,1,1,1,2,2,9,6,6,8,1,9,2,5,5,2,1,8,5,2,3,10]
*/
