class Solution {
public:
    int subSequence(string& str1, string& str2, int i, int j , vector<vector<int>>& dp){
        if(i == str1.size() || j == str2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]) return dp[i][j] = 1 + subSequence(str1, str2, i+1, j+1, dp);

        //advace str1
        int choice1 = subSequence(str1, str2, i + 1, j, dp);

        //advance str2
        int choice2 = subSequence(str1, str2, i, j + 1, dp);

        return dp[i][j] = max(choice1, choice2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return subSequence(text1, text2, 0, 0, dp);
    }
};
