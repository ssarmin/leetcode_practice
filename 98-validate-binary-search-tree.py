# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def check(self, root: Optional[TreeNode], l_val: int, r_val:int) -> bool:
        if not root:
            return True
        if root.val >= l_val:
            return False
        if root.val <= r_val:
            return False
        
        return self.check(root.left, root.val, r_val) and self.check(root.right, l_val, root.val)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.check(root, math.inf, -math.inf)

"""
[120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]
[1,null,null]
[1,null]
[-2147483648,-2147483648]
"""
