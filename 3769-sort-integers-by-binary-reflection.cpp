//https://leetcode.com/problems/sort-integers-by-binary-reflection
class Solution {
public:
    int get_binary_reflection(int val){
        int res = 0;
        while(val){
            int bit = val & 1;
            res = res | bit;
            res = res << 1;
            val = val >> 1;
        }
        return res;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        unordered_map<int, int> m;//value -> index
        vector<pair<int, int>> v;
        for(int i=0; i<nums.size(); i++){
            int val = get_binary_reflection(nums[i]);
            if(!m.count(nums[i]))
                v.push_back({val, nums[i]});
            m[nums[i]]++;
        }
        vector<int> res;
        sort(v.begin(), v.end());
        vector<pair<int, int>> prev;
        for(int i=0; i<v.size(); i++){
            if(prev.size() == 0){
                prev.push_back({v[i].second, v[i].first});
                continue;
            }
            if(v[i].first == prev.back().second){
                prev.push_back({v[i].second, v[i].first});
            }else{
                sort(prev.begin(), prev.end());
                for(auto p: prev){
                    int count = m[p.first];
                    while(count--){
                        res.push_back(p.first);
                    }
                }
                prev.clear();
                prev.push_back({v[i].second, v[i].first});
            }
        }
        sort(prev.begin(), prev.end());
        for(auto p: prev){
            int count = m[p.first];
            while(count--){
                res.push_back(p.first);
            }
        }
        prev.clear();
        return res;
    }
};
