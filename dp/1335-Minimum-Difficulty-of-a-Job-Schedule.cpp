class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<int>& jobs, int d, int i, int prevSum){
        if(i >= jobs.size() && d == 0) return 0;
        if(d == 0 && i < jobs.size()) return INT_MAX;
        if(dp[i][d] != -1) return dp[i][d];
        int curSum =0;
        int res = INT_MAX;
        for(int j = i; j < jobs.size() - d + 1; j++){
            curSum = max(curSum, jobs[j]);
            int next = rec(jobs, d-1, j + 1, curSum);
            if(next < INT_MAX){
                res = min(res, curSum + next);
            }
        }
        return dp[i][d] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        dp.assign(jobDifficulty.size()+1, vector<int>(d+1, -1));
        return rec(jobDifficulty, d, 0, 0);
    }
};
