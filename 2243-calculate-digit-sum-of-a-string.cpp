// https://leetcode.com/problems/calculate-digit-sum-of-a-string/
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string temp = "";
            for(auto i=0; i<s.size(); i=i+k){
                int sum = 0;
                int count = 0;
                for(int count=0; count<k && count+i < s.size(); count++){
                    sum += s[count+i] - '0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};
/*
"1234"
2
"1111"
4
"012"
4
"999999"
3
"1"
2
"123"
3
"9999999999"
2
"54321"
4
*/
