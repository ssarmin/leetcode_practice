//https://leetcode.com/problems/h-index
class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int, int> m;
        for(int cit: citations){
            m[cit]++;
        }
        int val = 0;
        for(auto it=m.rbegin(); it!=m.rend(); it++){
            it->second += val;
            val = it->second;
        }
        int hIndex = 0;
        for(auto it: m){
            hIndex = max(hIndex, min(it.first, it.second));
        }

        return hIndex;
    }
};


// [1]
// [1,1,1,1]
// [7,7,7,7] 
// [9,9,8,8,7,7,6,6,5] 
// [1,3,1] 
// [0,0,0,0,0,9,9,9,7,7,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,9,9,9,7,7,1,1,1,1,1,1,1,1,1,1] 
// [0,0,1,1,1,3,3,3,3,3,3,7,7,7,8,8,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6] 
// [1,1,1,1,2,2,2,3,3,4,4,4,3,5,5,2,5] 
// [3,0,6,1,5] 
// [3,0,6,1,5,3,0,6,1,5] 
// [7,7,7,8,8] 
// [1,1,1,1,2,2,2,3,3]
// [11, 12]
// [100]
// [0,1,3,5,5,6]
// [0,1,3,5,5,5,6]
// [0,1,3,5,5,5,5,6]
// [0,1,3,5,5,5,5,5,6]
// [0,1,3,5,5,5,6]
