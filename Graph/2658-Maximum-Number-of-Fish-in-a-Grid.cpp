class Solution {
public:
    vector<vector<bool>>visited;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j>= grid[0].size()) return 0;
        if(visited[i][j] || grid[i][j] == 0) return 0;
        
        // take
        visited[i][j] = true;
        return grid[i][j] + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int res =0;
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
