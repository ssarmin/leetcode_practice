//https://leetcode.com/problems/implement-stack-using-queues
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int val = q.front();
        q.pop();
        q = temp;
        return val;
    }
    
    int top() {
        queue<int> temp;
        int val = q.front();
        while(q.size() > 0){
            val = q.front();
            temp.push(q.front());
            q.pop();
        }
        q = temp;
        return val;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// ["MyStack","push","push","top","pop","empty"]
// [[],[1],[2],[],[],[]]
// ["MyStack","push","push","push","push","push","top","pop","empty","pop","pop"]
// [[],[1],[8],[3],[9],[2],[],[],[],[],[]]
// ["MyStack", "push", "push", "push", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "pop", "empty"]
// [[],[1], [2], [3], [4], [5], [6], [7], [8], [9], [], [], [], [], [], [], [], [], [], []]
// ["MyStack", "push", "push", "push", "pop", "pop", "push", "push", "top"]
// [[],[1], [2], [3], [], [], [4], [5], []]
// ["MyStack", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop", "pop", "empty"]
// [[], [2], [4], [6], [8], [9], [], [], [], [], [], []]
// ["MyStack", "push", "push", "push", "top", "pop", "push", "top", "pop"]
// [[], [1], [4], [6], [], [], [9], [], []]
// ["MyStack","push","pop","empty"]
// [[],[1],[],[]]
