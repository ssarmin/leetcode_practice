//https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;

        int index1 = 0;
        int index2 = 0;
        for(; index1<m; index1++){
            if(nums1[index1] > nums2[index2]){
                swap(nums1[index1], nums2[index2]);
                int i = index2;
                while(i+1 < n && nums2[i] > nums2[i+1]){
                    swap(nums2[i], nums2[i+1]);
                    i++;
                }
            }
        }
        for(; index1<m+n; index1++){
            nums1[index1] = nums2[index2];
            index2++;
        }
    }
};

Time Complexity: O(Mn)

// Extra testcases:
// [2,3,5,7,0,0,0,0]
// 4
// [2,4,5,6]
// 4

// [2,5,6,0,0,0]
// 3
// [1,2,3]
// 3
