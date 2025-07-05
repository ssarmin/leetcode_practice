//https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion
class Solution {
public:
    string concatHex36(int n) {
        long deci = 1L*n*n;
        long tri = 1L*deci*n;
        string temp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string first = "";
        while(deci){
            int val = deci%16;
            first = temp[val] + first;
            deci = deci/16;
        }
        string sec = "";
        while(tri){
            int val = tri%36;
            sec = temp[val] + sec;
            tri = tri/36;
        }
        return first+sec;
    }
};
//1000
//1
