https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* res = head;
        ListNode* prev = nullptr;

        while(head && head->next){
            bool flag = true;
            while(head->next && head->val == head->next->val){
                head = head->next;
                flag = false;
            }
            if(prev == nullptr){
                if(flag){
                    prev = head;
                }else{
                    prev = head->next;
                    if(head->val == res->val)
                        res = head->next;
                }
            }else{
                if(flag){
                    prev = head;
                }else{
                    prev->next = head->next;
                    if(head->val == res->val)
                        res = head->next;
                }
            }
            head = head->next;
        }
        return res;
    }
};

// []
// [-3,-1,0,0,0,3,3]
// [1,1]
// [1,1,2]
// [1,1,2,2]
// [1,1,2,2,3]
// [1,2,3,3,4,4,5]
// [1,1,1,2,3]
