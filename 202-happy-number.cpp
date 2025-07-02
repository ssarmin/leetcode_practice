//https://leetcode.com/problems/happy-number
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> visit;
        while(n != 1){
            int val = 0;
            while(n){
                val += (n%10)*(n%10);
                n = n/10;
            }
            if(visit.find(val) != visit.end()){
                return false;
            }
            visit[val] = true;
            n = val;
        }
        return true;
    }
};

// 1
// 7
// 1111111
// 2147483647
