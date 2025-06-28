// https://leetcode.com/problems/min-stack

class MinStack {
public:
    vector<pair<int, int>> v; //<val, min>
    int index = 0;
    MinStack() {
    }
    
    void push(int val) {
        if(v.size() == 0){
            v.push_back({val, val});
        }else{
            if(index == 0)
                v[index] = {val,val};
            else{
                // v[index] = {val, min(val, v[index-1].second)};
                int min_val = min(val, v[index-1].second);
                if(index < v.size())
                    v[index] = {val, min_val};
                else
                    v.push_back({val, min_val});
            }
        }
        index++;
    }
    
    void pop() {
        index--;
    }
    
    int top() {
        return v[index-1].first;
    }
    
    int getMin() {
        return v[index-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// ["MinStack","push","push","push","push","pop","getMin","pop","getMin","pop","getMin"]
// [[],[512],[-1024],[-1024],[512],[],[],[],[],[],[]]
// ["MinStack","push","push","push","getMin","top","pop","getMin"]
// [[],[-2],[0],[-1],[],[],[],[]]
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
// ["MinStack","push","push","getMin","getMin","push","getMin","getMin","top","getMin","pop","push","push","getMin","push","pop","top","getMin","pop"]
// [[],[-10],[14],[],[],[-20],[],[],[],[],[],[10],[-7],[],[-7],[],[],[],[]]
