//https://leetcode.com/problems/simplify-path
class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss (path);
        string word;
        char delim = '/';
        vector<string> v;
        while (getline (ss, word, delim)) {
            v.push_back(word);
            cout << word << endl;
        }
        stack<string> _stck;
        for(auto str: v){
            if(str.size() == 0)
                continue;
            if(str == ".")
                continue;
            if(str == ".."){
                if(!_stck.empty()){
                    _stck.pop();
                }
            }else{
                _stck.push(str);
            }
        }

        string res = "";
        while(!_stck.empty()){
            res = "/" + _stck.top() + res;
            _stck.pop();
        }
        return (res.size() == 0)? "/" : res;
    }
};

"/a/../../b/../c//.//"
"/../..ga/b/.f..d/..../e.baaeeh./.a"
"/hello../world"
"/..hidden"
"/hidden.."
"//.//"
"/a//b////c/d//././/.."
"/.a"
"/../"
"/.../a/../b/c/../d/./"
"/.....hidden"
"/../ab/bc/cd/ef"
"/home/../../.."
"/.././em/jl///../.././../E/"
