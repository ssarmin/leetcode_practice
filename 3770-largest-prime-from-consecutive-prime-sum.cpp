//https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum
class Solution {
public:
    unordered_map<int, bool> m;
    void update(int num){
        if(num == 1)
            m[1] = false;
        if(num == 2 || num == 3)
            m[num] = true;
        if(num%2 == 0)
            m[num] = false;
        if(m.count(num))
            return;
        for(int i=3; i*i<=num; i = i+2){
            if(num%i == 0){
                m[num] = false;
                return;
            }
        }
        m[num] = true;
    }
    int largestPrime(int n) {
        if(n == 1)
            return 0;
        if(n == 2)
            return 2;
        vector<int> v;
        v.push_back(2);
        m[2] = true;
        int res = 2;
        int sum = 2;
        for(int i=3; i<=n; i=i+2){
            update(i);
            if(m[i]){
                sum += i;
            }
            if(sum > n)
                break;
            update(sum);
            if(m[sum]){
                res = max(res, sum);
            }
        }
        return res;
    }
};
