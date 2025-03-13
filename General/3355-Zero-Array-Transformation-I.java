class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int []diffArr = new int[n + 1];
        for(int i = 0; i < queries.length; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            diffArr[l] += 1;
            diffArr[r + 1] -= 1;
        }
        // now perform prefix sum
        int curSum = 0;
        for(int i = 0; i < n; i++){
            diffArr[i] += curSum;
            curSum = diffArr[i];
            if(nums[i] > diffArr[i]) return false;
        }

        return true;
    }
}
