class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>>q;

        // Directions array
        vector<vector<int>> dirs = {{0,-1}, {0,1}, {1,0}, {-1,0}};

        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(grid[i][j] == 0) q.push({i, j}); // Push all gates to BFS
            }
        }

        // Apply multiple source BFS
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Traverse in all directions
            for(int i =0; i < 4; i++){
                int row = r + dirs[i][0];
                int col = c + dirs[i][1];
                if(row >= rows || row < 0 || col >= cols || col < 0 || grid[row][col] != INT_MAX) continue;

                grid[row][col] = grid[r][c] + 1;
                q.push({row,col});
            }
        }
    }
};
