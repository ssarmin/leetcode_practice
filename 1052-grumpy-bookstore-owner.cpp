//https://leetcode.com/problems/grumpy-bookstore-owner/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0;
        int val = 0;
        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                res += customers[i];
            }
        }
        val = res;
        int left = 0;
        int sum = 0;
        for(int right = 0; right < customers.size(); right++){
            if(grumpy[right] == 1){
                sum += customers[right];
            }
            while(right - left >= minutes){
                if(grumpy[left] == 1){
                    sum -= customers[left];
                }
                left++;
            }
            if(right - left < minutes){
                res = max(val+sum, res);
            }
        }
        return res;
    }
};

/*
[1,0,1,2,1,1,7,5]
[0,1,0,1,0,1,0,1]
3
[0]
[0]
1
[10,1,7]
[0,0,0]
2
[4,10,10]
[1,1,0]
2
[1, 2, 3, 4, 5]
[1, 1, 1, 0, 0]
3
[10, 1, 10, 1, 10, 1, 10]
[1, 1, 1, 1, 1, 1, 1]
1
[5, 8, 3, 6, 9, 4, 7]
[0, 1, 0, 1, 0, 1, 0]
3
*/
