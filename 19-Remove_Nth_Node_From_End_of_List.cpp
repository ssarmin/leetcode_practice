//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        while(n && temp){
            n--;
            temp = temp->next;
        }

        //if n is equal to the number of elements in the LinkedList
        //that means removing the first element from the LinkedList
        if(temp == NULL){
            return head->next;
        }
        ListNode* node = head;
        while(temp->next){
            node = node->next;
            temp = temp->next;
        }
        node->next = node->next->next;
        return head;
    }
};

//Time complexity: O(N)
