//https://leetcode.com/problems/reverse-linked-list-ii

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev_left = nullptr;
        ListNode* left_head = nullptr;

        ListNode* next_right = nullptr;
        ListNode* right_end = nullptr;
        ListNode* prev = nullptr;
        int pos = 1;
        ListNode* res = head;
        while(head){
            if(pos == left){
                prev_left = prev;
                left_head = head;
            }else if(pos == right){
                right_end = head;
                next_right = head->next;
                break;
            }
            pos++;
            prev = head;
            head = head->next;
        }
        right_end->next = nullptr;
        if(prev_left == nullptr){
            res = reverseList(left_head);
        }else{
            prev_left->next = reverseList(left_head);
        }
        left_head->next = next_right;
        return res;
    }
};

// [1,2,3,4,5]
// 2
// 4
// [5]
// 1
// 1
// [1,2,3,4,5]
// 2
// 3
// [1,2,3,4,5]
// 2
// 2
// [1,2,3,4,5]
// 1
// 4
// [1,2,3,4,5]
// 1
// 5
// [1,2,3,4,5]
// 5
// 5
// [1,2]
// 1
// 2
