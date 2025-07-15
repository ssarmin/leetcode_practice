//https://leetcode.com/problems/unique-paths
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int> (n, 0));

        for(int r=0; r<m; r++){
            v[r][0] = 1;
        }

        for(int c=0; c<n; c++){
            v[0][c] = 1;
        }

        for(int r = 1; r < m; r++){
            for(int c = 1; c < n; c++){
                v[r][c] = v[r-1][c] + v[r][c-1];
            }
        }

        return v[m-1][n-1];
    }
};

// 1
// 1
// 10
// 15
// 1
// 100
// 100
// 1
