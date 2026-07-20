class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l = s.split()
        if(len(l) != len(pattern)):
            return False
        m_ch_str = {}
        m_str_ch = {}
        for i in range(len(pattern)):
            if pattern[i] in m_ch_str and m_ch_str[pattern[i]] != l[i]:
                return False
            if l[i] in m_str_ch and m_str_ch[l[i]] != pattern[i]:
                return False
            else:
                m_ch_str[pattern[i]] = l[i]
                m_str_ch[l[i]] = pattern[i]
        
        return True

"""
"abba"
"dog dog dog dog"
"jquery"
"jquery"
"a"
"dog cat"
"""
