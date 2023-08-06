class Solution:
    def isUgly(self, n: int) -> bool:
        if n <= 0:
            return False
        elif n == 1:
            return True

        l = [2, 3, 5]
        for i in l:
            while n % i == 0:
                n /= i

        if n != 1:
            return False
        else:
            return True


