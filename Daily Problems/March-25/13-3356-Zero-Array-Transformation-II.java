class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] diffArr = new int[n + 1];
        int prefSum = 0;
        int k = 0;
        for(int i = 0; i < n; i++){
            while(nums[i] > prefSum + diffArr[i]){
                if(k == queries.length) return -1;
                int l = queries[k][0];
                int r = queries[k][1];
                if(r < i){
                    k++;
                    continue;
                }
                diffArr[Math.max(i, l)] += queries[k][2];
                diffArr[r + 1] -= queries[k][2];
                k++;
            }
            prefSum += diffArr[i];
        }
        return k;
    }
}
