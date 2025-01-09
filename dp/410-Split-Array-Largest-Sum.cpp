class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<int>& nums, int k, int i){
        if(i >= nums.size()) return 0;
        if(k == 0) return INT_MAX;

        if(dp[i][k] != -1) return dp[i][k];
        int cur = 0;
        int ans = INT_MAX;
        for(int j = i; j < nums.size() - k+1; j++){
            cur += nums[j];
            ans = min(ans,max(cur, rec(nums, k-1, j+1)));
        }
        return dp[i][k] = ans;
        
    }

    int splitArray(vector<int>& nums, int k) {
        dp.assign(nums.size()+1, vector<int>(k+1, -1));
        return rec(nums, k, 0);
    }
};
