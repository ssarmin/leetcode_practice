//https://leetcode.com/problems/fibonacci-number
//optimized solution
//Bottom-up approach
class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return n;
        int val0 = 0;
        int val1 = 1;
        for(int i=2; i<=n; i++){
            int val = val0+val1;
            val0 = val1;
            val1 = val;
        }
        return val1;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)


//Top-down approach
class Solution {
public:
    unordered_map<int, int> m;
    int fib(int n) {
        if(m.find(n) != m.end())
            return m[n];
        if(n < 2){
            m[n] = n;
            return n;
        }
        m[n] = fib(n-1) + fib(n-2);
        return m[n];
    }
};
//Time Complexity: O(n)
//Space Complexity: O(n) stack
