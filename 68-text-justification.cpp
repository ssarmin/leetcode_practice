//https://leetcode.com/problems/text-justification
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int end = 0;
        int curr_len = 0;
        vector<string> res;
        while(end < words.size()){
            curr_len += words[end].size();
            int temp_len = curr_len + end - start;
            if(temp_len == maxWidth){
                string temp = "";
                while(start < end){
                    temp += words[start];
                    temp += " ";
                    start++;
                }
                temp += words[start];
                start++;
                res.push_back(temp);
                curr_len = 0;
            }else if(temp_len > maxWidth){
                if(start == end-1){
                    string temp = words[end-1];
                    while(temp.size() < maxWidth){
                        temp += " ";
                    }
                    res.push_back(temp);
                    curr_len = words[end].size();
                    start = end;
                }else{
                    int space_needed = maxWidth - curr_len + words[end].size();
                    int num_words = end - 1 - start;
                    bool flag = true;
                    if(space_needed % num_words != 0){
                        flag = false;
                    }
                    string temp = "";
                    while(start < end){
                        int spaces = space_needed/num_words;
                        if(!flag){
                            spaces++;
                            space_needed -= spaces;
                            num_words--;
                            if(space_needed % num_words == 0){
                                flag = true;
                            }
                        }
                        temp += words[start];
                        start++;
                        if(start < end){
                            for(int k=0; k<spaces; k++){
                                temp += " ";
                            }
                        }
                    }
                    res.push_back(temp);
                    curr_len = words[end].size();
                }
            }
            end++;
        }

        if(start <= words.size()-1){
            string temp = "";
            while(start < end){
                temp += words[start];
                start++;
                if(start < end)
                    temp += " ";
            }
            while(temp.size() < maxWidth){
                temp += " ";
            }
            res.push_back(temp);
        }
        return res;
    }
};


// ["What","must","be","shall","be."]
// 12
// ["What","must","be","acknowledgment","shall","be"]
// 16
// ["Here","is","an","example","of","text","justification."]
// 14
// ["My","momma","always","said,","Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."]
// 20
// ["a","b","c","d"]
// 3
// ["a"]
// 2
// ["a","b","c","d"]
// 8
// ["a","b","c","d", "asdfghjkl"]
// 9
