class Solution {
public:
    vector<bool>dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size()+1, false);
        dp[s.size()] = true;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(auto word: wordDict){
                if(s.size() < word.size() + i) continue;
                string prefix = s.substr(i, word.size());
                if(prefix == word){
                    dp[i] = dp[i + word.size()];
                    if(dp[i] == true) break;
                }
            }
        }
        return dp[0];
    }
};
