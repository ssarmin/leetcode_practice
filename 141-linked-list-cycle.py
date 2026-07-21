# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False
        fast = head.next.next

        while fast:
            head = head.next
            fast = fast.next
            if fast:
                fast = fast.next
            else:
                return False
            if fast == head:
                return True

        return False
            
        
