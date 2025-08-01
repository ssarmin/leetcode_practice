//https://leetcode.com/problems/decode-string
class Solution {
public:
    string decodeString(string s) {
        stack<pair<bool, string>> _stack; //num -> true, str ->false
        for(int i=0; i<s.size();){
            string num = "";
            while(i<s.size() && s[i] >= '0' && s[i] <= '9'){
                num += s[i];
                i++;
            }
            if(i<s.size() && s[i] == '['){
                i++;
                _stack.push({true, num});
            }
            string str = "";
            while(i<s.size() && s[i] >= 'a' && s[i] <= 'z'){
                str += s[i];
                i++;
            }
            if(str != ""){
                string temp = str;
                while(!_stack.empty() && !_stack.top().first){
                    temp = _stack.top().second + temp;
                    _stack.pop();
                }
                _stack.push({false, temp});
            }
            if(i<s.size() && s[i] == ']'){
                str = "";
                if(!_stack.empty()){
                    str = _stack.top().second;
                    _stack.pop();
                }
                num = "";
                if(!_stack.empty()){
                    num = _stack.top().second;
                    _stack.pop();
                }
                int n = stoi(num);
                string temp = "";
                while(n--){
                    temp += str;
                }

                while(!_stack.empty() && !_stack.top().first){
                    temp = _stack.top().second + temp;
                    _stack.pop();
                }
                _stack.push({false, temp});
                i++;
            }
        }
        string str = "";
        while(!_stack.empty()){
            str = _stack.top().second + str;
            _stack.pop();
        }
        return str;
    }
};

// "2[3[a2[c]]d]e"
// "9[9[9[9[a]]]]"
// "3[a]2[bc]"
// "3[a2[c]]"
// "2[abc]3[cd]ef"
// "c3[2[a]1[b]]d"
// "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"
// "ef3[a2[c]]xy"
// "11[2[a]]"
