class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = Counter(nums)
        return count.most_common(1)[0][0]


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        m = {}
        for n in nums:
            m[n] = m.get(n, 0) + 1
        
        m_num, m_count = -1, -1
        for num, count in m.items():
            if(count > m_count):
                m_count = count
                m_num = num

        return m_num
        
