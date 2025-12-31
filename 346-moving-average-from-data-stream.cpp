//https://leetcode.com/problems/moving-average-from-data-stream
class MovingAverage {
public:
    queue<int> q;
    long long sum;
    int max_size;
    MovingAverage(int size) {
        max_size = size;
        sum = 0;
    }
    
    double next(int val) {
        while(q.size() >= max_size){
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (1.0*sum / (1.0*q.size()));
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
