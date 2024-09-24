class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        arr1_pre = set()

        for val in arr1:
            while val not in arr1_pre and val > 0:
                arr1_pre.add(val)
                val //= 10
            
        longest_prefix = 0
        for val in arr2:
            while val not in arr1_pre and val >0:
                val //= 10
            if val > 0:
                longest_prefix = max(longest_prefix, len(str(val)))
        
        return longest_prefix
