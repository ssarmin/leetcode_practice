//https://leetcode.com/problems/design-memory-allocator
class Allocator {
public:
    unordered_map<int, vector<int>> m;
    vector<int> v;
    int empty = 0;
    Allocator(int n) {
        v.assign(n, -1);
        empty = n;
    }
    int allocate(int size, int mID) {
        if(size > empty)
            return -1;
        int start = -1;
        int end = -1;
        int index = 0;
        while(index < v.size()){
            if(v[index] == -1){
                while(index < v.size() && v[index] == -1){
                    if(start == -1){
                        start = index;
                    }
                    end = index;
                    index++;
                }
                if((end - start + 1) >= size){
                    for(int s = 0; s<size; s++){
                        v[s + start] = mID;
                        m[mID].push_back(s + start);
                    }
                    empty -= size;
                    return start;
                }
            }else{
                index++;
                start = -1;
                end = -1;
            }
        }
        if(start != -1 && (end - start + 1) >= size){
            for(int s = 0; s<size; s++){
                v[s + start] = mID;
                m[mID].push_back(s + start);
            }
            empty -= size;
            return start;
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        if(m.count(mID)){
            int count = m[mID].size();
            empty += count;
            for(auto i: m[mID]){
                v[i] = -1;
            }
            m.erase(mID);
            return count;
        }
        return 0;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
/*
["Allocator","allocate"]
[[5],[6,1]]
["Allocator","allocate","allocate","freeMemory"]
[[5],[5,1],[1,2],[1]]
["Allocator","allocate","freeMemory","freeMemory"]
[[10],[4,1],[1],[1]]
["Allocator","allocate","allocate","allocate","allocate","freeMemory"]
[[10],[2,1],[2,2],[2,1],[2,3],[1]]
["Allocator","allocate","allocate","allocate","freeMemory","allocate","allocate"]
[[10],[3,1],[3,2],[3,3],[2],[2,4],[2,5]]
["Allocator","allocate","allocate","allocate","freeMemory","allocate"]
[[1],[1,100],[1,100],[1,100],[100],[1,100]]
*/
