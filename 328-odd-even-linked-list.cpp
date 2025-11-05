//https://leetcode.com/problems/odd-even-linked-list
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* odd = nullptr;
        ListNode* even = nullptr;
        bool flag_odd = true;
        while(head){
            if(flag_odd){
                if(odd == nullptr){
                    odd = head;
                }else{
                    odd->next = head;
                    odd = odd->next;
                }
            }else{
                if(even == nullptr){
                    even = head;
                }else{
                    even->next = head;
                    even = even->next;
                }
            }
            head = head->next;
            flag_odd = !flag_odd;
        }
        odd->next = even_head;
        even->next = nullptr;
        return odd_head;
    }
};

// [1]
// [1,3]
// [1,3,5]
// [1,4,6,7,3]
