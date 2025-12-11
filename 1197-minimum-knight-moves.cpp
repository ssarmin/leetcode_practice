//https://leetcode.com/problems/minimum-knight-moves
class Solution {
public:
    long distance(int a, int b, int x, int y){
        return ((a - x)*(a - x)) + ((b - y)*(b-y)); 
    }
    int minKnightMoves(int x, int y) {
        int move = 0;
        queue<pair<int, int>> pq;
        pq.push({0, 0});

        int dx[] = {1, -1, 2, -2, 1, -1, 2, -2};
        int dy[] = {2, 2, 1, 1, -2, -2, -1, -1};
        unordered_map<int, unordered_set<int>> m_visit;
        m_visit[0].insert(0);
        while(!pq.empty()){
            int size = pq.size();
            while(size--){
                auto [a, b] = pq.front();
                pq.pop();
                if(a == x && b == y){
                    return move;
                }
                for(int i=0; i<8; i++){
                    int r = a + dx[i];
                    int c = b + dy[i];
                    if(r > 300 || c > 300 || r < -300 || c < -300 || abs(r) + abs(c) > 300)continue;
                    if(m_visit.count(r) && m_visit[r].count(c))continue;
                    pq.push({r, c});
                    m_visit[r].insert(c);
                }
            }
            move++;
        }
        return -1;
    }
};
/*
93
-194
1
1
-87
83
-35
211
300
0
81
22
*/
