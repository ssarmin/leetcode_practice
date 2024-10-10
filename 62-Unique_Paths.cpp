//https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1)
            return 1;
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i=1; i<n; i++){
            v[0][i] = 1;
        }

        for(int i=1; i<m; i++){
            v[i][0] = 1;
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                v[j][i] = v[j][i-1] + v[j-1][i];
            }
        }

        return v[m-1][n-1];
    }
};

/*
Extra test cases:
m = 1
n = 1

m = 1
n = 2

m = 10
n = 10
*/
