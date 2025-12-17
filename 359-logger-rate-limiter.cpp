//https://leetcode.com/problems/logger-rate-limiter
class Logger {
public:
    unordered_map<string, int> m;
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.count(message)){
            if(m[message] <= timestamp){
                m[message] = timestamp + 10;
                return true;
            }
            return false;
        }else{
            m[message] = timestamp + 10;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
