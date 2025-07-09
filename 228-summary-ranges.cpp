//https://leetcode.com/problems/summary-ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<string> res;
        int start = nums[0];
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == (prev+1)){
                prev++;
            }else{
                if(start != prev){
                    string str = to_string(start) + "->" + to_string(prev);
                    res.push_back(str);
                }else{
                    string str = to_string(start);
                    res.push_back(str);
                }
                start = nums[i];
                prev = nums[i];
            }
        }

        if(start != prev){
            string str = to_string(start) + "->" + to_string(prev);
            res.push_back(str);
        }else{
            string str = to_string(start);
            res.push_back(str);
        }

        return res;
    }
};

// []
// [-2147483648,-2147483647,2147483647]
// [-2147483648,-2147483647,2147483647]
// [-1,2]
// [-1]
// [-5,-4,-2,-1,0,1,2]
// [0,2,3,4,6,8,9]
// [-1,0,2,9]
