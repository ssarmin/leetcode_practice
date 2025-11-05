//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head->next->next;
        ListNode* slow = head;

        while(fast){
            if(fast->next){
                fast = fast->next;
            }else{
                break;
            }
            slow = slow->next;
            if(fast->next){
                fast = fast->next;
            }else{
                break;
            }
        }
        slow->next = slow->next->next;
        return head;
    }
};
// [1,3,4,7,1,2,6]
// [1,2,3,4]
// [1,3,4,7,1,6]
// [1,3,4,7,1]
// [1,2,3]
// [2,1]
// [1]
