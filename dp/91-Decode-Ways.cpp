class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int>dp;
        dp[s.size()] = 1;
        return dfs(0, s, dp);
    }
    int dfs(int index, string& s, unordered_map<int, int>& dp){
        if(dp.count(index) != 0)
            return dp[index];
        if(s[index] == '0')
            return 0;
        
        int res = dfs(index + 1, s, dp);
        if(index + 1 < s.size()){
            if(s[index] == '1' || s[index] == '2' && s[index + 1] <= '6')
                res+= dfs(index + 2, s, dp);
        }
        dp[index] = res;
        return res;
    }
};
