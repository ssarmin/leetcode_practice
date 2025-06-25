// https://leetcode.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        int carry = 0;
        ListNode* temp = head;
        while(l1 || l2 || carry){
            int val = 0;
            if(l1){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                val += l2->val;
                l2 = l2->next;
            }
            if(carry){
                val += carry;
            }
            ListNode* node = new ListNode(val%10);
            carry = val/10;
            temp->next = node;
            temp = temp->next;
        }
      return head->next;
    }
};
