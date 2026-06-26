class Solution:
    def isHappy(self, n: int) -> bool:
        s = set()
        while(n != 1):
            val = 0
            while(n != 0):
                n, digit = divmod(n, 10)
                val = val + digit*digit
            if(val in s):
                return False
            s.add(val)
            n = val
        return True
