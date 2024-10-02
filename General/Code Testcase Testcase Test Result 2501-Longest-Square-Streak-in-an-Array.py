class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums = set(sorted(nums))
        seq = 0
        for num in list(nums):
            curr = 0
            curr_num = num
            while curr_num in nums:
                curr += 1
                curr_num = curr_num ** 2
            seq = max(seq, curr)


        if seq < 2: 
            return -1
        return seq
