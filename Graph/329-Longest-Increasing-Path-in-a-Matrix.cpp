class Solution {
    vector<vector<int>>dp;
public:
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int choice4 = 0;
        if(i-1 >=0 && matrix[i][j] < matrix[i-1][j])
            choice1 = 1 + dfs(matrix, i-1, j);   // up

        if(i+1 < matrix.size() && matrix[i][j] < matrix[i+1][j])
            choice2 = 1 + dfs(matrix, i+1, j);    // down


        if(j-1 >= 0 && matrix[i][j] < matrix[i][j-1])
            choice3 = 1 + dfs(matrix, i, j-1);    // left

        if(j+1 < matrix[0].size() && matrix[i][j] < matrix[i][j+1])
            choice4 = 1 + dfs(matrix, i, j+1);    // right
            
        return dp[i][j] = max({choice1, choice2, choice3, choice4});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(),vector<int>(matrix[0].size(), -1));
        int res = 0;
        for(int i =0; i<matrix.size(); i++){
            for(int j =0; j<matrix[0].size(); j++){
                res = max(res, 1+dfs(matrix, i, j));
            }
        }
        return res;
    }
};
