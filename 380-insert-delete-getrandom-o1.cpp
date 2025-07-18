//https://leetcode.com/problems/insert-delete-getrandom-o1
class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.count(val))
            return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val) == 0)
            return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%s.size();
        auto it = next(s.begin(), index);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


// ["RandomizedSet","insert","insert","remove","insert","insert","insert","remove","remove","insert","remove","insert","insert","insert","insert","insert","getRandom","insert","remove","insert","insert"]
// [[],[3],[-2],[2],[1],[-3],[-2],[-2],[3],[-1],[-3],[1],[-2],[-2],[-2],[1],[],[-2],[0],[-3],[1]]
// ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
// [[],[0],[0],[0],[],[0],[0]]
// ["RandomizedSet","insert","insert","insert","getRandom","insert","remove","getRandom","insert","getRandom","insert"]
// [[],[0],[0],[2],[],[3],[1],[],[3],[],[2]]
// ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
// [[],[0],[0],[0],[],[0],[0]]
// ["RandomizedSet", "insert", "insert", "remove", "remove"]
// [[], [5], [5], [5], [5]]
// ["RandomizedSet", "insert", "insert", "insert", "remove", "getRandom"]
// [[], [10], [20], [30], [20], []]
// ["RandomizedSet", "insert", "remove", "insert", "getRandom"]
// [[], [2], [2], [2], []]
// ["RandomizedSet", "insert", "insert", "getRandom"]
// [[], [1], [1], []]
