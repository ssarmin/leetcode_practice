//https://leetcode.com/problems/design-browser-history
class BrowserHistory {
public:
    vector<string> v;
    int curr_index;
    int last_index;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        curr_index = 0;
        last_index = 0;
    }
    
    void visit(string url) {
        curr_index++;
        if(v.size() == curr_index){
            v.push_back(url);
        }else{
            v[curr_index] = url;
        }
        last_index = curr_index;
    }
    string back(int steps) {
        int index = max(curr_index - steps, 0);
        curr_index = index;
        return v[index];
    }
    
    string forward(int steps) {
        int index = min(curr_index + steps, last_index);
        curr_index = index;
        return v[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
/*
["BrowserHistory","back","visit","back","visit","visit","back","visit","visit","back","visit","visit","forward","visit","forward","forward","visit","forward","forward"]
[["rlglu.com"],[2],["zxowmd.com"],[4],["gbnssie.com"],["bqo.com"],[6],["cq.com"],["pbh.com"],[5],["ijt.com"],["tnsiso.com"],[7],["xjxi.com"],[3],[9],["zlnx.com"],[3],[7]]
*/
