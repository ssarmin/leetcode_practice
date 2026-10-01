//https://leetcode.com/problems/alternating-digit-sum/
class Solution {
public:
    int alternateDigitSum(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        n = stoi(str);
        bool pos = true;
        int res = 0;
        while(n){
            if(pos){
                res += n%10;
            }else{
                res -= n%10;
            }
            pos = !pos;
            n = n/10;
        }
        return res;
    }
};

//10
