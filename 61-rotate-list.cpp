// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;

        int count = 0;
        ListNode* node = head;
        ListNode* last = nullptr;
        while(node){
            count++;
            last = node;
            node = node->next;
        }
        k = k%count;
        node = head;
        for(int i=1; i<count-k; i++){
            node = node->next;
        }
        if(last){
            last->next = head;
        }
        head = node->next;
        node->next = nullptr;

        return head;
    }
};


// []
// 3
// [1]
// 4
// [1,2]
// 200000000
// [1,2,3,4,5]
// 2
// [0,1,2]
// 4
// [1]
// 1
// [1,2,3]
// 10
// []
// 0
// [1,2]
// 0
// [1,2]
// 2
// [0,1,2]
// 4
// []
// 1
// [1,2]
// 1
