https://leetcode.com/problems/find-the-celebrity
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_map<int, unordered_set<int>> m;
        unordered_map<int, unordered_set<int>> m_rev;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(knows(i, j)){
                    m[j].insert(i);
                    m_rev[i].insert(j);
                }
                if(knows(j, i)){
                    m[i].insert(j);
                    m_rev[j].insert(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            if((m[i].size() == n-1) && m_rev[i].size() == 0){
                return i;
            }
        }
        return -1;
    }
};

/*
[[1,1],[0,1]]
[[1,0],[0,1]]
[[1,1,1],[0,1,1],[0,0,1]]
[[1,1,0],[0,1,0],[1,1,1]]
[[1,1,1,1],[0,1,1,1],[0,0,1,1],[0,0,0,1]]
[[1,1,0,0],[0,1,0,0],[1,1,1,1],[1,1,0,1]]
[[1,1,1,0],[0,1,1,0],[0,0,1,0],[1,1,1,1]]
[[1,1,1,1,1],[0,1,1,1,1],[0,0,1,1,1],[0,0,0,1,1],[0,0,0,0,1]]
*/
