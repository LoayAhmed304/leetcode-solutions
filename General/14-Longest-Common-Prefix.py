class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs = sorted(strs)
        first, last = strs[0], strs[-1]
        res = ""

        # Because if sorted, the first and last strings will have the lowest possible common substr
        for i in range(min(len(first), len(last))):
            if first[i] != last[i]:
                return res
            res += first[i]

        return res
