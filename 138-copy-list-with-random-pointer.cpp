//https://leetcode.com/problems/copy-list-with-random-pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* copyRandomList(Node* head) {
        Node* n_head = new Node(0);
        Node* temp = n_head;

        Node* it = head;
        while(it){
            temp->next = new Node(it->val);
            m[it] = temp->next;
            temp = temp->next;
            it = it->next;
        }
        temp->next = nullptr;
        temp = n_head;
        while(head){
            Node* random = head->random;
            temp->next->random = m[random];
            head = head->next;
            temp = temp->next;
        }
        return n_head->next;   
    }
};
