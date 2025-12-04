// https://leetcode.com/problems/reverse-integer
class Solution {
public:
    int reverse(int x) {
        string max_str = to_string(INT_MAX);
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        if(x >= 0){
            if(str.size() == max_str.size()){
                if(str > max_str)
                    return 0;
                else
                    return stoi(str);
            }else{
                return stoi(str);
            }
        }else{
            max_str.back() += '1' - '0';
            str.pop_back();
            if(str.size() == max_str.size()){
                if(str > max_str)
                    return 0;
                else{
                    str.insert(str.begin(), '-');
                    return stoi(str);
                }
            }else{
                str.insert(str.begin(), '-');
                    return stoi(str);
            }
        }
    }
};

/*
1463847412
1534236469
1563847412
-1563847412
-1036
-2147483648
-846384742
*/
