class Solution:
    def longestCommonPrefix(self, words: List[str]) -> str:
        words.sort()
        index = 0
        for i_0 in range(len(words[0])):
            for i in range(1, len(words)):
                if(words[0][i_0] != words[i][i_0]):
                    return words[0][0:i_0]
        return words[0]
