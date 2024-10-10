class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        indices = [ i for i in range(len(nums)) ]
        
        indices.sort(key=lambda i: (nums[i], i))

        min_index = len(nums)
        max_width = 0

        for i in indices:
            max_width = max(max_width, i-min_index)
            min_index = min(min_index, i)
        
        return max_width
