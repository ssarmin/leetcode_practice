// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> un_set(wordList.begin(), wordList.end());
        if(un_set.find(endWord) == un_set.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int s=0; s<size; s++){
                string str = q.front();
                q.pop();
                for(int i=0; i<str.size(); i++){
                    for(char ch='a'; ch <= 'z'; ch++){
                        if(str[i] == ch)continue;
                        string temp = str;
                        temp[i] = ch;
                        if(un_set.find(temp) != un_set.end()){
                            if(temp == endWord){
                                return count+1;
                            }
                            q.push(temp);
                            un_set.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

// "a"
// "c"
// ["a","b","c"]
// "hog"
// "cog"
// ["cog"]
// "hot"
// "dog"
// ["hot","dog","dot"]
// "hot"
// "dog"
// ["dog","dot"]
// "a"
// "c"
// ["a","b","c"]
// "hit"
// "cog"
// ["hot","dot","dog","lot","log"]
// "leet"
// "code"
// ["lest","leet","lose","code","lode","robe","lost"]
// "hbo"
// "qbx"
// ["abo","hco","hbw","ado","abq","hcd","hcj","hww","qbq","qby","qbz","qbx","qbw"]
// "hit"
// "hit"
// ["hot","dot","dog","lot","log","cog"]
// "qa"
// "sq"
// ["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
