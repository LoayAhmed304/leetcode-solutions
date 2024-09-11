class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ) return 0;
        if(visited[i][j]) return 0;
        if(grid[i][j] == 0) return 0;

        visited[i][j] = true;
        
        // Dfs over all 4 directions
        return 1 + dfs(grid, visited, i+1, j) + dfs(grid, visited, i-1, j) + dfs(grid, visited, i, j+1) + dfs(grid, visited, i, j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));

        int area = 0;
        for(int i =0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int cur = dfs(grid, visited, i, j);
                    area = max(area, cur);
                }
            }
        }
        return area;
    }
};
