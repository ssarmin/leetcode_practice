//https://leetcode.com/problems/merge-two-sorted-lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* node = NULL;
        while(list1 && list2){
            if(list1->val < list2->val){
                if(node == NULL){
                    head = list1;
                    node = head;
                }else{
                    node->next = list1;
                    node = node->next;
                }
                list1 = list1->next;
            }else{
                if(node == NULL){
                    head = list2;
                    node = head;
                }else{
                    node->next = list2;
                    node = node->next;
                }
                list2 = list2->next;
            }
        }
        if(list1){
            if(node == NULL){
                    head = list1;
                    node = head;
            }else{
                    node->next = list1;
            }
        }
        
        if(list2){
            if(node == NULL){
                    head = list2;
                    node = head;
            }else{
                    node->next = list2;
            }
        }

        return head;
    }
};

// Extra testcases:
// [2]
// [1]
// [-9, 3]
// [5, 7]
