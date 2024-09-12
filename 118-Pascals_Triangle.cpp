//https://leetcode.com/problems/pascals-triangle/description/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp{1};
        res.push_back(temp);

        for(int i=2; i<=numRows; i++){
            vector<int> v;
            v.push_back(1);
            vector<int> last = res[res.size()-1];
            for(int j=1; j<last.size(); j++){
                v.push_back(last[j-1]+last[j]);
            }
            v.push_back(1);
            res.push_back(v);
        }

        return res;
    }
};

//Time complexity:  O(n*n)
