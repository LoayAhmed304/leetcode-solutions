class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        size = len(nums)
        k = k % size
        new_nums = nums * 2
        nums[:] = new_nums[ size - k : 2 * size - k]
