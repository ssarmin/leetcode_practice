//https://leetcode.com/problems/dot-product-of-two-sparse-vectors
class SparseVector {
public:
    vector<int> v;
    SparseVector(vector<int> &nums) {
        v = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> v1 = v;
        vector<int> v2 = vec.v;
        int res = 0;
        for(int i=0; i<v2.size(); i++){
            if(v1[i] && v2[i])
                res += (v1[i]*v2[i]);
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
