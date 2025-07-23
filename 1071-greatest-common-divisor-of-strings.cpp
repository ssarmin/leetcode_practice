//https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        unordered_set<char> s_1(str1.begin(), str1.end());
        unordered_set<char> s_2(str2.begin(), str2.end());
        if(s_1.size() != s_2.size())
            return "";
        
        string res = "";
        int size = s_1.size();
        while(size <= str1.size() && size <= str2.size()){
            cout << size << endl;
            if(str1.size() % size == 0 && str2.size() % size == 0){
                int index = size;
                string str = str1.substr(0, size);
                cout << str << endl;
                bool flag = true;
                while(index + str.size() <= str1.size()){
                    string temp = str1.substr(index, size);
                    if(temp != str){
                        flag = false;
                        break;
                    }
                    index = index + size;
                }
                index = size;
                while(index + str.size() <= str2.size() && flag){
                    string temp = str2.substr(index, size);
                    if(temp != str){
                        flag = false;
                        break;
                    }
                    index = index + size;
                }
                if(flag){
                    res = str;
                }
            }
            size++;
        }
        return res;
    }
};

// "TAUXXTAUXXTAUXXTAUXXTAUXX"
// "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
// "ABCDEF"
// "ABC"
// "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
// "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
// "A"
// "AA"
