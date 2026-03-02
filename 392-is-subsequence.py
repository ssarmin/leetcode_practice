class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        index = 0
        for ch in s:
            flag = False
            for i in range(index, len(t)):
                if(ch == t[i]):
                    index = i+1
                    flag = True
                    break
            if flag == False:
                return False
        
        return True
            
