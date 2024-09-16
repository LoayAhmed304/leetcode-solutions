class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        if len(timePoints) < 2:
            return 0
        n = len(timePoints)
        
        minutes_array = []
        for point in timePoints:
            time = point.split(':')
            minutes_array.append(int(time[0])*60 + int(time[1]))

        minutes_array = sorted(minutes_array)

        # Initialize res
        res = abs(minutes_array[0] - minutes_array[1]) % 1438
        for i in range(n - 1):
            diff = abs(minutes_array[i] - minutes_array[i+1]) % 1438
            res = min(res, diff)
        
        # Check first and last index
        last_diff = (24*60 - abs(minutes_array[0] - minutes_array[n-1])) % 1438
        res = min(res, last_diff)

        return res
