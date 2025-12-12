//https://leetcode.com/problems/counting-elements
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto a: arr){
            m[a]++;
        }
        int count = 0;
        for(auto a: m){
            if(m.count(a.first+1)){
                count += a.second;
            }
        }
        return count;
    }
};
