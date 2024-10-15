class Solution:
    def minimumSteps(self, s: str) -> int:
        zeroes, total = 0,0
        i = len(s) - 1
        while(i >=0):
            if s[i] == '0':
                zeroes += 1
            else:
                total += zeroes
            i -= 1
        return total
