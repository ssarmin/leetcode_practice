//https://leetcode.com/problems/exclusive-time-of-functions
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<tuple<int, int, int>> _stack;//id, start_time, excution time so far
        for(int i=0; i<logs.size(); i++){
            istringstream ss (logs[i]);
            string word;
            char delim = ':';
            int index = 0;
            string command = "";
            int function_id = -1;
            int time = -1;
            while (getline (ss, word, delim)) {
                if(index == 0){
                    function_id = stoi(word);
                }else if(index == 1){
                    command = word;
                }else{
                    time = stoi(word);
                }
                index++;
            }
            if(command == "start"){//push
                if(!_stack.empty()){
                    auto [f_id, t, ex_time] = _stack.top();
                    if(ex_time == INT_MIN){
                        ex_time = time - 1 - t + 1;//handle for 0 start
                    }else{
                        ex_time += time - 1 - t + 1;
                    }
                    _stack.top() = {f_id, t, ex_time};
                }
                _stack.push({function_id, time, INT_MIN});
            }else{//pop
                auto [f_id, t, ex_time] = _stack.top();
                if(ex_time == INT_MIN){
                    ex_time = time - t + 1;
                }else{
                    ex_time += time - t + 1;
                }
                res[f_id] += ex_time;
                _stack.pop();
                if(!_stack.empty()){
                    auto [f_id, t, ex_time] = _stack.top();
                    t = time + 1;
                    _stack.top() = {f_id, t, ex_time};
                }
            }
        }
        return res;
    }
};
/*
3
["1:start:0","0:start:2","1:start:3","2:start:4","2:end:4","1:end:6","0:end:7","1:end:8"]
2
["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
1
["0:start:2","0:end:5"]
*/
