//https://leetcode.com/problems/count-symmetric-integers/
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        while(low <= high){
            string str = to_string(low);
            low++;
            if(str.size()%2 != 0)
                continue;
            int sum = 0;
            for(int i=0; i<str.size()/2; i++){
                sum += str[i] - '0';
            }
            for(int i = str.size()/2; i<str.size(); i++){
                sum -= str[i] - '0';
            }
            if(sum == 0)
                res++;
        }
        return res;
    }
};

/*
1
100
1200
1230
53
56
22
22
35
53
25
58
1
10000
99
9999
*/
