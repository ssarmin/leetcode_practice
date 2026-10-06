//https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> m_count, m_res;
        int res = 0;
        for(auto &n: nums){
            m_count[n]++;
        }
        for(auto n: nums){
            if(m_res.count(n)){
                res += m_res[n];
            }else if(n.size() >= target.size()){
                m_res[n] = 0;
            }else{
                string last_part = target.substr(n.size(), target.size() - n.size());
                if(n+last_part != target)
                continue;
                int val = 0;
                if(m_count.count(last_part)){
                    if(n == last_part)
                        val += m_count[last_part] - 1;
                    else
                        val += m_count[last_part];
                }
                m_res[n] = val;
                res += m_res[n];
            }
        }
        return res;
    }
};

//--------------------------------------------------------------------------------------
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i].size() >= target.size())continue;
            for(int j=i+1; j<nums.size(); j++){
                if(target == (nums[i]+nums[j]))
                    res++;
                if(target == (nums[j]+nums[i]))
                    res++;
            }
        }
        return res;
    }
};
/*
["9","93","9","2","32","32"]
"932"
*/
