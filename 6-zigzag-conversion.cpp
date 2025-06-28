//https://leetcode.com/problems/zigzag-conversion
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        if(numRows == 1)
            return s;
        for(int r=0; r<numRows; r++){
            if(r == 0 || r == numRows-1){
                int index = r;
                while(index < s.size()){
                    res += s[index];
                    index = index + (numRows-1)*2;
                }
            }else{
                int index = r;
                while(index < s.size()){
                    res += s[index];
                    int slow_index = index + (numRows-1)*2 - 2*r;

                    if(slow_index < s.size()){
                        res += s[slow_index];
                    }
                    index = index + (numRows-1)*2;
                }
            }
        }

        return res;
    }
};


// "ABC"
// 2
// "AB"
// 2
// "ABCDEFGHIJKLMN"
// 2
// "ABCDEFGHIJKLMN"
// 4
// "ABCDEFGHIJKLMN"
// 5
// "ABCD"
// 2
