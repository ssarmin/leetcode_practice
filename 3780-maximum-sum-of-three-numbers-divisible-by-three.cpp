//https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(auto n: nums){
            if(n%3 == 0){
                m[0].push_back(n);
            }else if(n%3 == 1){
                m[1].push_back(n);
            }else if(n%3 == 2){
                m[2].push_back(n);
            }
        }
        int max_val = 0;
        vector<int> v_0 = m[0];
        vector<int> v_1 = m[1];
        vector<int> v_2 = m[2];
        sort(v_0.rbegin(), v_0.rend());
        sort(v_1.rbegin(), v_1.rend());
        sort(v_2.rbegin(), v_2.rend());
        
        if(m.count(0) && m[0].size() >= 3){
            int sum = 0;
            for(int i=0; i<3; i++){
                sum += v_0[i];
            }
            max_val = max(max_val, sum);
        }
        if((m.count(1) && m[1].size() >= 3)){
            int sum = 0;
            for(int i=0; i<3; i++){
                sum += v_1[i];
            }
            max_val = max(max_val, sum);
        }
        if((m.count(2) && m[2].size() >= 3)){
            int sum = 0;
            for(int i=0; i<3; i++){
                sum += v_2[i];
            }
            max_val = max(max_val, sum);
        }
        if(m.count(0) && m[0].size() >= 1 && m.count(1) && m[1].size() >= 1 && m.count(2) && m[2].size() >= 1){
            int sum = 0;
            sum += v_0[0];
            sum += v_1[0];
            sum += v_2[0];
            max_val = max(max_val, sum);
        }
        return max_val;
    }
};
