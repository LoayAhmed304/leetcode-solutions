class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        events = []

        for interval in intervals:
            events.append((interval[0], 1))
            events.append((interval[1]+1, -1))
        
        events.sort(key=lambda x:(x[0], x[1]))

        sep_intervals = 0
        max_sep_intervals = 0

        for event in events:
            sep_intervals += event[1]
            max_sep_intervals = max(max_sep_intervals, sep_intervals)
        
        return max_sep_intervals
