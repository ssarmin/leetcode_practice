//https://leetcode.com/problems/car-fleet
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for(int i=0; i<position.size(); i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        stack<double> s;
        int res = 0;
        for(int i=0; i<v.size(); i++){
            double t = (double)(target - v[i].first)/(1.0*v[i].second);
            if(s.empty() || s.top() < t){
                s.push(t);
            }
        }
        return s.size();
    }
};

// 10
// [0,4,2]
// [2,1,3]
// 31
// [5,26,18,25,29,21,22,12,19,6]
// [7,6,6,4,3,4,9,7,6,4]
// 20
// [6,2,17]
// [3,9,2]
// 10
// [8,3,7,4,6,5]
// [4,4,4,4,4,4]
