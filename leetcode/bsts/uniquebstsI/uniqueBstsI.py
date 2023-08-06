import itertools

class Solution:
    def numTrees(self, n: int) -> int:
        def fak(n: int):
            cur = 1
            while n > 1:
                cur = cur * n
                n -= 1
            return cur
            
        # (2n)! / ((n + 1)! * n!)
        return int((fak(2*n) / (fak(n+1) * fak(n))))

