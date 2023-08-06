# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

import math


class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def preorder(r: TreeNode, l):
            if r is not None:
                # visit node
                l.append(r.val)
                # left subtree
                preorder(r.left, l)
                # right subtree
                preorder(r.right, l)

        s = []
        preorder(root, s)

        return len(s)