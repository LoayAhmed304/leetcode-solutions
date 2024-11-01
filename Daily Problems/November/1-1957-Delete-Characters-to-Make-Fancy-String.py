class Solution:
    def makeFancyString(self, s: str) -> str:
        res = ""
        for char in s:
            if len(res) >= 2:
                if res[-1] == char and res[-2] == char: continue
            res += char
        return res
        
