class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        freq = []
        res = []
        for i in range(len(nums)):
            if nums[i] == x:
                freq.append(i)
        
        for q in queries:
            if q > len(freq):
                res.append(-1)
            else:
                res.append(freq[q-1])
        return res
