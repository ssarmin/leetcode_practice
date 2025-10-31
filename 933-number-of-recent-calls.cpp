//https://leetcode.com/problems/number-of-recent-calls
class RecentCounter {
public:
    vector<pair<int, int>> v;
    int count;
    RecentCounter() {
        count = 0;
    }
    
    int ping(int t) {
        v.push_back({t, count});
        int res = 0;
        for(int i=v.size()-1; i>=0; i--){
            if(v[i].first < (t-3000))
                break;
            res++;
        }
        count++;
        return res;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// ["RecentCounter","ping","ping","ping","ping","ping"]
// [[],[1178],[1483],[1563],[4054],[4152]]
