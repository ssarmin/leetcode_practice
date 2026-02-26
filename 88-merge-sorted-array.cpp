//https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m-1;
        int index2 = n-1;
        int i = m+n-1;
        for(; i>=0 && index1 >= 0 && index2 >= 0; i--){
            if(nums1[index1] >= nums2[index2]){
                nums1[i] = nums1[index1];
                index1--;
            }else{
                nums1[i] = nums2[index2];
                index2--;
            }
        }
        for(; i>=0 && index2 >= 0; i--){
            nums1[i] = nums2[index2];
                index2--;
        }
    }
};

/* Extra testcases:

[2,3,5,7,0,0,0,0]
4
[2,4,5,6]
4
[2,5,6,0,0,0]
3
[1,2,3]
3
*/
