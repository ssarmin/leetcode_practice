class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        d = dict()
        d_rev = dict()
        s_list = s.split()
        if(len(s_list) != len(pattern)):
            return False
        for index in range(len(pattern)):
            if pattern[index] in d:
                if(d[pattern[index]] != s_list[index]):
                    return False
            d[pattern[index]] = s_list[index]
        
        for index in range(len(s_list)):
            if s_list[index] in d_rev:
                if(d_rev[s_list[index]] != pattern[index]):
                    return False
            d_rev[s_list[index]] = pattern[index]
        
        return True
