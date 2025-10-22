//https://leetcode.com/problems/largest-rectangle-in-histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int max_area = 0;
        for(int i=0; i<heights.size(); i++){
            max_area = max(max_area, heights[i]);
            if(s.empty()){
                s.push({heights[i], i});
            }else{
                if(s.top().first <= heights[i]){
                    s.push({heights[i], i});
                }else{
                    int index = -1;
                    while(!s.empty() && s.top().first > heights[i]){
                        index = s.top().second;
                        int area = (i - s.top().second) * s.top().first;
                        max_area = max(area, max_area);
                        s.pop();
                    }
                    if(index != -1)
                    s.push({heights[i], index});
                }
            }
        }
        while(!s.empty()){
            int area = (heights.size() - s.top().second) * s.top().first;
            max_area = max(area, max_area);
            s.pop();
        }
        return max_area;
    }
};

// [1,1]
// [2,3]
// [2,1,2]
// [4,3,5,5,9,2,8,4,7,2,3,8,3,5,4,7,9]
// [2,1,2]
// [3,6,5,7,4,8,1,0]
