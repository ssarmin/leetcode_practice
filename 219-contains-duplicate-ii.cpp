//https://leetcode.com/problems/contains-duplicate-ii
//optimized solution
//storing last index
//as we need to find the distance between two indices less than k!

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.count(nums[i]) && i - m[nums[i]] <= k)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }

        for(auto it: m){
            if(it.second.size() > 1){
                vector<int> v = it.second;
                for(int i = 0; i<v.size()-1; i++){
                    if(abs(v[i+1] - v[i]) <= k)
                        return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }

        for(auto it: m){
            if(it.second.size() > 1){
                vector<int> v = it.second;
                for(int i = 0; i<v.size(); i++){
                    for(int j = i+1; j<v.size(); j++){
                        if(abs(v[j] - v[i]) <= k)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};

// [1,0,1,1]
// 1
// [99, 99]
// 2
// [99, 99]
// 1
// [1, 5, 1, 0]
// 2
