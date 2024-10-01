class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainderMap = defaultdict(int)

        for num in arr:
            rem = ((num%k) + k) % k # Handles negative numbers
            remainderMap[rem] += 1
        
        for key, val in remainderMap.items():
            if key == 0:
                if val % 2 != 0:
                    return False
            
            elif val != remainderMap[k - key]:
                return False

        return True
