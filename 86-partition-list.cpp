//https://leetcode.com/problems/partition-list
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = nullptr;
        ListNode* small = nullptr;
        ListNode* big = nullptr;
        ListNode* big_head = nullptr;
        while(head){
            if(head->val < x){
                if(small == nullptr){
                    small = head;
                    res = small;
                }else{
                    small->next = head;
                    small = small->next;
                }
                head = head->next;
                small->next = nullptr;
            }else{
                if(big == nullptr){
                    big = head;
                    big_head = big;
                }else{
                    big->next = head;
                    big = big->next;
                }
                head = head->next;
                big->next = nullptr;
            }
        }
        if(small == nullptr)
            return big_head;
        small->next = big_head;
        return res;
    }
};

[3,6,5,2,4,8,1,7]
4
[]
4
[1]
3
[3,4,2]
34
[6,3,2,4,2,3,5]
4
[6,3,2,4,2,3,5]
1
[6,3,2,4,2,3,5]
40
