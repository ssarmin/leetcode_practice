//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
class Solution {
public:
    int maxVowels(string str, int k) {
        int maxCount = 0;
        int count = 0;
        for(int i=0; i<k; i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                count++;
            }
        }

        maxCount = max(maxCount, count);

        for(int i=k; i<str.size(); i++){
            if(str[i-k] == 'a' || str[i-k] == 'e' || str[i-k] == 'i' || str[i-k] == 'o' || str[i-k] == 'u'){
                count--;
            }
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                count++;
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

// "rrrrrryyyyyy"
// 5
// "weallloveyou"
// 7
