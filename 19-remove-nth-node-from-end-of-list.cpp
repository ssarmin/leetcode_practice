//https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* adv = head;
        for(int i=0; i<n; i++){
            adv = adv->next;
        }

        ListNode* slow = head;
        ListNode* prev = NULL;
        while(adv){
            adv = adv->next;
            prev = slow;
            slow = slow->next;
        }

        if(prev){
            prev->next = slow->next;
            return head;
        }else{
            return head->next;
        }
    }
};

// [1,2,3,4,5]
// 1
// [1,2,3,4,5]
// 3
// [1,2,3,4,5]
// 4
// [1,2,3,4,5]
// 5
