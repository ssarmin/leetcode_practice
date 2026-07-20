class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for ch in set(ransomNote):
            if ransomNote.count(ch) > magazine.count(ch):
                return False

        return True

"""
"a"
"ab"
"baa"
"abc"
"aa"
"caab"
"bg"
"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"
"""
