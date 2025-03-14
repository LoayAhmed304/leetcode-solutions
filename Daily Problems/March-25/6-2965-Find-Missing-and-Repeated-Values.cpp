class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>mp(n * n + 1);
        int a, b;
        int shouldSum = pow(n, 2) * (pow(n, 2) + 1) / 2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mp[grid[i][j]]++ == 1) a = grid[i][j];
                shouldSum -= grid[i][j];
            }
        }
        
        return {a, shouldSum + a};
    }
};
