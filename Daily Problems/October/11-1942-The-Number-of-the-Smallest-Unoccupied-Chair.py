class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        target = times[targetFriend]
        times.sort()

        chair_time = [0]*len(times)
        for time in times:
            for i in range(len(times)):
                if chair_time[i] <= time[0]:
                    chair_time[i] = time[1]
                    if time == target:
                        return i
                    break
        return 0
