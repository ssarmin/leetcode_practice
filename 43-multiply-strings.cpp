//https://leetcode.com/problems/multiply-strings
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string res = "";
        int iter = 0;
        for(int i=num1.size()-1; i>=0; i--){
            int carry = 0;
            int index = iter;
            iter++;
            for(int j=num2.size()-1; j>=0; j--){
                int val = ((num1[i] - '0')*(num2[j] - '0')) + carry;
                if(index >= res.size()){
                    res.push_back((val%10) + '0');
                    carry = val/10;
                }else{
                    int n = res[index] - '0' + val;
                    res[index] = (n%10) + '0';
                    carry = n/10;
                }
                index++;
            }
            while(carry){
                if(index >= res.size()){
                    res.push_back((carry%10) + '0');
                    carry = carry/10;
                }else{
                    int n = res[index] - '0' + carry;
                    res[index] = (n%10) + '0';
                    carry = n/10;
                }
                index++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// "324352345243523452465265426347"
// "4262457564857857695672345234123413452345645847686"
// "123456789"
// "987654321"
// "0"
// "12433245"
