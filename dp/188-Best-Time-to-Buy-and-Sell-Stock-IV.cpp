class Solution {
public:
    vector<vector<vector<int>>>dp;
    int rec(vector<int>&prices, int k, int i, bool bought){
        if(k == 0 || i >= prices.size()) return 0;
        if(dp[bought][i][k]!= -1) return dp[bought][i][k];
        // choice1, pass
        int choice1 = rec(prices, k, i+1, bought);
        
        // choice2, sell/buy (take action)
        int choice2 = 0;
        if(bought)// if bought -> sell
            choice2 = max(choice2, prices[i] + rec(prices, k-1, i+1, false));
        else // if sold -> buy
            choice2 = max(choice2, rec(prices, k, i+1, true) - prices[i]);
        return dp[bought][i][k] = max(choice1, choice2);
    }

    int maxProfit(int k, vector<int>& prices) {
        dp.assign(2, vector<vector<int>>(prices.size(), vector<int>(k + 1, -1)));
        return rec(prices, k, 0, false);
    }
};
