class Solution {
public:
    void dfs(vector<vector<int>>&grid, int curSteps, int& maxSteps, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == -1) return;

        maxSteps = max(curSteps, maxSteps);
        curSteps++;

        if(i - 1 >= 0 && j + 1 < grid[0].size() && grid[i-1][j+1] >grid[i][j]){
            dfs(grid, curSteps, maxSteps, i - 1, j + 1);
        }
        if(j+1 < grid[0].size() && grid[i][j+1] >grid[i][j]){

            dfs(grid, curSteps,maxSteps, i, j + 1);
           
        }
        if(i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i+1][j+1] >grid[i][j]){
            
            dfs(grid, curSteps,maxSteps, i + 1, j + 1);
        }
        grid[i][j] = -1;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            dfs(grid, 0, res,i, 0);
        }
        return res;
    }
};
