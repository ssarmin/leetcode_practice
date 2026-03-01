class Solution:
    def isPalindrome(self, s: str) -> bool:
        str = "".join(char for char in s if char.isalnum()).lower()
        str_reverse = str[::-1]
        if str_reverse == str:
            return True
        return False
