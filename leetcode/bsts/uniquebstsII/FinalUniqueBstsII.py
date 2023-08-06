# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

import itertools


class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n is 1:
            return list([TreeNode(val=1)])
        arr = [i for i in range(1, n + 1)]
        comb = list(itertools.permutations(arr, n))

        def preorder(r: TreeNode, l):
            if r is not None:
                # visit node
                l.append(r.val)
                # left subtree
                preorder(r.left, l)
                # right subtree
                preorder(r.right, l)
            else:
                l.append(None)

        def insert_tree(r: TreeNode, x: int):
            if x < r.val:
                if r.left != None:
                    insert_tree(r.left, x)
                else:
                    r.left = TreeNode(val=x)
            elif x > r.val:
                if r.right != None:
                    insert_tree(r.right, x)
                else:
                    r.right = TreeNode(val=x)

        ret = []
        ret2 = []

        for i in comb:
            root = None
            for j in i:
                if root is None:
                    root = TreeNode(val=j)
                else:
                    insert_tree(root, j)
            l = []
            preorder(root, l)
            while l[-1] is None:
                l = l[0:-1]

            if l not in ret:
                ret.append(l)
                ret2.append(root)

        return ret2



