# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    max_depth = 0
    def getDepth(self, root: Optional[TreeNode], depth):
        if not root:
            return
        depth += 1
        self.max_depth = max(self.max_depth, depth)
        self.getDepth(root.left, depth)
        self.getDepth(root.right, depth)
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.getDepth(root, 0)
        return self.max_depth
