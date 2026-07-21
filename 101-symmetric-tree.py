# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def is_mirror(self, l: Optional[TreeNode], r: Optional[TreeNode]):
        if not l and not r:
            return True
        if not l or not r or l.val != r.val:
            return False
        return self.is_mirror(l.left, r.right) and self.is_mirror(l.right, r.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return not root or self.is_mirror(root.left, root.right)
