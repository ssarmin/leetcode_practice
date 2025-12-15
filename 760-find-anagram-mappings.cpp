//https://leetcode.com/problems/find-anagram-mappings
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        res.resize(nums1.size());
        unordered_map<int, vector<int>> m;
        for(int i=0; i<nums2.size(); i++){
            m[nums2[i]].push_back(i);
        }
        for(int i=0; i<nums1.size(); i++){
            res[i] = m[nums1[i]].back();
            if(m[nums1[i]].size() == 1){
                m.erase(nums1[i]);
            }else if(m[nums1[i]].size() > 1){
                m[nums1[i]].pop_back();
            }
        }
        return res;
    }
};
