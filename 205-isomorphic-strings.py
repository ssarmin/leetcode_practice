class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m_s_t = {}
        m_t_s = {}

        for char1, char2 in zip(s, t):
            if (char1 in m_s_t and m_s_t[char1] != char2) or (char2 in m_t_s and m_t_s[char2] != char1):
                return False
            else:
                m_s_t[char1] = char2
                m_t_s[char2] = char1

        return True

"""
"bbbaaaba"
"aaabbbba"
"badc"
"baba"
"""
