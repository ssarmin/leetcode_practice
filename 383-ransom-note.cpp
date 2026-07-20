class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {0};
        for(auto ch: magazine){
            m[ch - 'a']++;
        }
        for(auto ch: ransomNote){
            int index = ch - 'a';
            if(m[index] > 0){
                m[index]--;
            }else{
                return false;
            }
        }
        return true;
    }
};

/*
"a"
"ab"
"baa"
"abc"
"aa"
"caab"
"bg"
"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
*/
