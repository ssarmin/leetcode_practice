//https://leetcode.com/problems/plus-one-linked-list
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
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        while(head){
            ListNode* curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* node = head;
        int carry = 1;
        ListNode* prev = nullptr;
        while(node){
            int val = node->val + carry;
            carry = val/10;
            node->val = val%10;
            prev = node;
            node = node->next;
        }
        if(carry){
            prev->next = new ListNode(1);
            prev = prev->next;
            prev->next = nullptr;
        }
        return reverse(head);
    }
};
