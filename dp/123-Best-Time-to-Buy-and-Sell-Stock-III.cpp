class Solution {
public:
    vector<vector<vector<int>>>dp;
    int rec(vector<int>& prices, int i, bool bought, int k){
        if(i >= prices.size()) return 0;
        if(k == 0) return 0;
        if(dp[bought][i][k] != -1) return dp[bought][i][k];
        int c1 = 0;
        int c2 = 0;
        // default case-> skip current
        c1 = rec(prices, i+1, bought, k);
        // case bought -> sell current
        if(bought){
            c2 = prices[i] + rec(prices, i+1, false, k - 1);
        }else{ // case not bought -> buy current
            c2 = rec(prices, i+1, true, k) - prices[i];
        }
        return dp[bought][i][k] = max(c1, c2);
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(2, vector<vector<int>>(prices.size(), vector<int>(3, -1)));
        return rec(prices, 0, 0, 2);
    }
};
