//https://leetcode.com/problems/counting-bits
class Solution {
public:
    int get_count(int n){
        int count = 0;
        for(int i=0; i<32; i++){
            count += (n >> i) & 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0; i<=n; i++){
            v.push_back(get_count(i));
        }
        return v;
    }
};

// 2234
// 53562
// 78442
// 100000
