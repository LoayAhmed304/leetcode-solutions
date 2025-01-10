class Solution {
public:
    vector<vector<int>>dp;

    int rec(vector<int>&nums, int start, int end){
        if(end < start) return 0;
        if(dp[start][end]!= -1) return dp[start][end];
        int ans = INT_MIN;
        
        for(int i = start; i <= end; i++){
            int cur = nums[i] * nums[start-1] * nums[end+1];
            int res = rec(nums, start, i-1) + rec(nums, i+1, end) + cur;
            ans = max(ans, res);
        }
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        dp.assign(nums.size()+1, vector<int>(nums.size()+1, -1));
        return rec(nums, 1, nums.size()-2);
    }
};
