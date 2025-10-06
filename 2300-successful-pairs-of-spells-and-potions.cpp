//https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for(auto a: spells){
            int start = 0;
            int end = potions.size()-1;
            while(start <= end){
                int mid = (end - start)/2 + start;
                if((long long)potions[mid]*a >= success){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
            res.push_back(potions.size()-1-end);
        }
        return res;
    }
};

// [5,1,3]
// [1,2,3,4,5]
// 7
// [3,1,2]
// [8,5,8]
// 16
// [15,39,38,35,33,25,31,12,40,27,29,16,22,24,7,36,29,34,24,9,11,35,21,3,33,10,9,27,35,17,14,3,35,35,39,23,35,14,31,7]
// [25,19,30,37,14,30,38,22,38,38,26,33,34,23,40,28,15,29,36,39,39,37,32,38,8,17,39,20,4,39,39,7,30,35,29,23]
// 317
// [4,2,1]
// [3,9,6,2]
// 10
// [7,3,9]
// [1,2,3,4,5,6]
// 20
// [2,5,8]
// [3,1,4]
// 12
// [10,2]
// [2,2,3,5]
// 15
// [100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000]
// [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000]
// 100000
// [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
// [5,10,15,20,25,30,35,40,45,50]
// 250
