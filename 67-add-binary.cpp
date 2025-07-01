//https://leetcode.com/problems/add-binary
optimized code:
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int sum = 0;
        string res = "";
        while(i >= 0 || j >= 0 || sum){
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }
            char ch = (sum%2) + '0';
            res = ch + res;
            sum = sum/2;
        }

        return res;
    }
};





class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int i = 0;
        for(; i<a.size() && i < b.size(); i++){
            int val = carry + a[i] - '0' + b[i] - '0';
            if(val == 3){
                res = "1" + res;
                carry = 1; 
            }else if(val == 2){
                res = "0" + res;
                carry = 1;
            }else if(val == 1){
                res = "1" + res;
                carry = 0;
            }else{
                res = "0" + res;
                carry = 0;
            }
        }

        for(; i<a.size(); i++){
            int val = carry + a[i] - '0';
            if(val == 3){
                res = "1" + res;
                carry = 1; 
            }else if(val == 2){
                res = "0" + res;
                carry = 1;
            }else if(val == 1){
                res = "1" + res;
                carry = 0;
            }else{
                res = "0" + res;
                carry = 0;
            }
        }

        for(; i<b.size(); i++){
            int val = carry + b[i] - '0';
            if(val == 3){
                res = "1" + res;
                carry = 1; 
            }else if(val == 2){
                res = "0" + res;
                carry = 1;
            }else if(val == 1){
                res = "1" + res;
                carry = 0;
            }else{
                res = "0" + res;
                carry = 0;
            }
        }

        if(carry){
            res = "1" + res;
        }

        return res;
    }
};

// "101110101010100101010101010101001010"
// "101010010100101001010100101010010101010101001010"
// "101010010100101001010100101010010101010101001010"
// "101110101010100101010101010101001010"
// "0"
// "0"
// "1"
// "1"
