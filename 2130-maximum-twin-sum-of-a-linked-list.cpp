//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head)
            return 0;
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int max_val = v[0];
        for(int i=0; i<v.size()/2; i++){
            v[i] += v[v.size()-1-i];
            max_val = max(max_val, v[i]);
        }
        return max_val;
    }
};

// [47,22,81,46,94,95,90,22,55,91,6,83,49,65,10,32,41,26,83,99,14,85,42,99,89,69,30,92,32,74,9,81,5,9]
// [7,57,13,31,17,65,32,3,97,22,7,20,69,35,69,75,13,33,50,80,64,71,15,28,2,27,39,48,13,22,84,5,51,46,26,78,56,63]
