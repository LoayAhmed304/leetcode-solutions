class Solution {
public:
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>& visited, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ) return;
        if(visited[i][j]) return;
        if(grid[i][j] == '0') return;

        visited[i][j] = true;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i-1,j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int res = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
