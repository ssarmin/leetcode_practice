//https://leetcode.com/problems/count-nice-pairs-in-an-array/
class Solution {
public:
    int get_rev(int n){
        int res = 0;
        while(n){
            res = 10*res + n%10;
            n = n/10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m_diff;

        int MOD = 1000000007;

        int res = 0;
        for(auto n: nums){
            int rev = get_rev(n);
            int diff = n - rev;
            if(m_diff.count(diff)){
                res = (res + m_diff[diff]) % MOD;
            }
            m_diff[diff]++;
        }
        return res;
    }
};

// ---------

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> m_diff;

        int MOD = 1000000007;

        int res = 0;
        for(auto n: nums){
            if(!m.count(n)){
                string temp = to_string(n);
                reverse(temp.begin(), temp.end());
                m[n] = stoi(temp);
            }
            
            int diff = n - m[n];
            if(m_diff.count(diff)){
                res = (res + m_diff[diff]) % MOD;
            }
            m_diff[diff]++;
        }
        return res;
    }
};
