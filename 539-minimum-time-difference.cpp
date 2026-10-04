//https://leetcode.com/problems/minimum-time-difference/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_set<string> s(timePoints.begin(), timePoints.end());
        if(s.size() < timePoints.size())
            return 0;
        vector<int> num;
        num.resize(timePoints.size());
        int index = 0;
        for(auto t: timePoints){
            string str1(t.begin(), t.begin()+2);
            string str2(t.begin()+3, t.end());
            num[index++] = (stoi(str1)*60 + stoi(str2));
        }
        sort(num.begin(), num.end());
        int min_val = INT_MAX;
        for(int i=1; i<num.size(); i++){
            min_val = min(num[i] - num[i-1], min_val);
        }
        min_val = min(min_val, 1440+num[0] - num.back());
        return min_val;
    }
};
// ["12:12","00:13"]
// ["23:59","00:00","12:12","00:13"]
// ["00:00","23:59","12:12","00:13","00:00"]
