class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        mp = {}
        sortedArr = sorted(set(arr))

        k = 1
        for num in sortedArr:
            mp[num] = k
            k += 1
        
       
        for i in range(len(arr)):
           arr[i] = mp[arr[i]]
        
        return arr

