//https://leetcode.com/problems/climbing-stairs/description/

// optimized solution:
class Solution {
public:
    int climbStairs(int n) {
        if(n < 4){
            return n;
        }

        int val1 = 2;
        int val2 = 3;
        for(int i=4; i<=n; i++){
            int val = val1+val2;
            val1 = val2;
            val2 = val;
        }

        return val2;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)



//Bottom-up / Tabulation solution
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3)
            return n;
        vector<int> v(n+1, 0);
        v[1] = 1;
        v[2] = 2;
        for(int i=3; i<=n; i++){
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};
//Time complexity: O(n)
//Space complexity: O(n)



//recursive solution
class Solution {
public:
    int climbStairs(int n) {
        if(n < 4)
            return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
//Time complexity: O(2^n)
//Space complexity: O(n) stack

//Top down with memorization solution
class Solution {
public:
    unordered_map<int, int> m;
    int climbStairs(int n) {
        if(m.find(n) != m.end()){
            return m[n];
        }
        if(n < 4){
            m[n] = n;
            return n;
        }
        m[n] = climbStairs(n-1) + climbStairs(n-2);
        return m[n];
    }
};
// Time complexity: O(n)
// Space Complexity: O(n)
