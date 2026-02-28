class Solution:
    def addBinary(self, a: str, b: str) -> str:
        len_a = len(a)-1
        len_b = len(b)-1
        sum = 0
        res = ""
        while(len_a >= 0 or len_b >= 0 or sum):
            if(len_a >= 0):
                sum = sum + int(a[len_a])
                len_a = len_a - 1

            if(len_b >= 0):
                sum = sum + int(b[len_b])
                len_b = len_b - 1

            res = str(sum%2) + res
            sum = sum//2
        
        return res
