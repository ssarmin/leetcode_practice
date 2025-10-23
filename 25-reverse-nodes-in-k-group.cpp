//https://leetcode.com/problems/reverse-nodes-in-k-group
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr || head->next == nullptr)
            return head;
        
        vector<ListNode*> prev_left;
        vector<ListNode*> left_head;
        vector<ListNode*> next_right;
        vector<ListNode*> right_end;
        ListNode* prev = nullptr;
        int pos = 1;
        ListNode* res = head;
        while(head){
            if(pos == 1){
                prev_left.push_back(prev);
                left_head.push_back(head);
            }else if(pos == k){
                right_end.push_back(head);
                next_right.push_back(head->next);
                pos = 0;
            }
            pos++;
            prev = head;
            head = head->next;
        }

        for(int i=0; i<right_end.size(); i++){
            right_end[i]->next = nullptr;
            if(i == 0){
                res = reverseList(left_head[i]);
            }else{
                prev_left[i] = left_head[i-1];
                prev_left[i]->next = reverseList(left_head[i]);
            }
            left_head[i]->next = next_right[i];
        }

        return res;
    }
};

// [1,2,3,4,5,6,7,9,3,5,2,2,4,6,3,4]
// 4
// [1,2,3,4,5]
// 5
// [1,2,3,4,5,6,7]
// 7
// [1,2,3,4,5,6,7,9,3,5,2,2,4,6,3,4,1,2,3,4,5,6,7,9,3,5,2,2,4,6,3,4,1,2,3,4,5,6,7,9,3,5,2,2,4,6,3,4,1,2,3,4,5,6,7,9,3,5,2,2,4,6,3,4,3,4,5,2,3]
// 4
