//https://leetcode.com/problems/first-unique-number
class FirstUnique {
public:
    unordered_map<int, int> m;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(auto n: nums){
            m[n]++;
            q.push(n);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty()){
            if(m[q.front()] == 1){
                return q.front();
            }
            q.pop();
        }
        return -1;
    }
    
    void add(int value) {
        m[value]++;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
