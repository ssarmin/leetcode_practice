//https://leetcode.com/problems/meeting-rooms-ii
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({intervals[0][1], intervals[0][0]});
        int count = 1;
        for(int i=1; i<intervals.size(); i++){
            if(pq.top().first <= intervals[i][0]){
                pq.pop();
            }
            pq.push({intervals[i][1], intervals[i][0]});
            count = max(count, (int)pq.size());
        }
        return count;
    }
};

/*
[[13,15],[1,13]]
[[1, 5], [2, 6], [3, 7], [4, 8], [5, 9], [6, 10], [7, 11], [8, 12]]
[[1,13],[6,9],[13,15],[16,17]]
*/

/*
Given an array of meeting time intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 10^4
0 <= start_i < end_i <= 10^6
*/
