//https://leetcode.com/problems/lfu-cache
class LFUCache {
public:
    int cap = 0;
    map<int, list<int>> m_counter;
    unordered_map<int, tuple<int, int, list<int>:: iterator>> m;//val, counter, list iter
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)){
            auto [val, counter, it] = m[key];
            m_counter[counter].erase(it);
            if(m_counter[counter].empty()){
                m_counter.erase(counter);
            }
            m_counter[counter+1].push_front(key);
            m[key] = {val, counter+1, m_counter[counter+1].begin()};
            return val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            auto [val, counter, it] = m[key];
            m_counter[counter].erase(it);
            if(m_counter[counter].empty()){
                m_counter.erase(counter);
            }
            counter++;
            m_counter[counter].push_front(key);
            m[key] = {value, counter, m_counter[counter].begin()};
        }else{
            while(m.size() >= cap){
                int low_counter = m_counter.begin()->first;
                int temp_key = m_counter[low_counter].back();
                cout << key << " " << low_counter << endl;
                m_counter[low_counter].pop_back();
                if(m_counter[low_counter].empty()){
                    m_counter.erase(low_counter);
                }
                m.erase(temp_key);
            }
            m_counter[1].push_front(key);
            m[key] = {value, 1, m_counter[1].begin()};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]
[[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
["LFUCache","put","put","put","put","get"]
[[2],[3,1],[2,1],[2,2],[4,4],[2]]
["LFUCache","put","put","get","put","get","get","put","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[6],[4,4],[3]]
["LFUCache","put","put","get","put","get","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
["LFUCache","get","put","get","put","put","get","get"]
[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]
[[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
*/
