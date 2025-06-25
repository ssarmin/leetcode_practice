// https://leetcode.com/problems/linked-list-cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while(node1 && node2){
            if(node1 == node2){
                return true;
            }
            node1 = node1->next;
            if(node2->next){
                node2 = node2->next->next;
            }else{
                return false;
            }
        }

        return false;
    }
};

// Extra testcases:
// []
// -1
