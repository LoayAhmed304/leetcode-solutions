class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        
        def to_vec(s1):
            arr = s1.split(" ")
            return arr
        s1 = to_vec(sentence1)
        s2 = to_vec(sentence2)
        if len(s1) == 1 and len(s2) == 1 and s1 != s2:
            return False

        n1, n2 = len(s1), len(s2)
        if n1 > n2:
            n1, n2 = n2, n1
            s1, s2 = s2, s1
        
        l, r1, r2 = 0, n1-1, n2-1

        while l < n1 and s1[l] == s2[l]:
            l += 1
        while r1 >= 0 and s1[r1] == s2[r2]:
            r2 -= 1
            r1 -= 1
        return r1<l

