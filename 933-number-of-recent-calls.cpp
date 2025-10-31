//https://leetcode.com/problems/number-of-recent-calls
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && t - q.front() > 3000){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// ["RecentCounter","ping","ping","ping","ping","ping"]
// [[],[1178],[1483],[1563],[4054],[4152]]
