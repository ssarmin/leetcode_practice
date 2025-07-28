//https://leetcode.com/problems/detect-squares
class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> m;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        m[point[0]][point[1]]++;//x, y
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int res = 0;
        for(auto &[y2, count]: m[x1]){
            if(y1 == y2)continue;
            int side = y1-y2;
            int x2 = x1+side;
            int x3 = x1-side;
            res += count * m[x2][y1] * m[x2][y2];
            res += count * m[x3][y1] * m[x3][y2];
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

// ["DetectSquares", "add", "add","add","count", "count","add", "count"]
// [[],[[1,1]], [[2,2]], [[1, 2]], [[2, 1]],  [[3, 3]], [[2, 2]], [[2, 1]]]
