// Main Approach
// First we count the number of islands
// Return 0 if we have more than 1 (already disconnected)
// When do we return 1?
// That's the challenge, that's why we'll loop over every single grid element
// And try to switch it to 0 and see if that'll disconnect the islands (become more than 1)
// If not, we'll restore the grid back to 1 and continue trying
// Otherwise, we'll just return 2 since 2 is the maximum number of days to disconnect any island

// Counting the islands
// We dfs over every grid element which is of value 1 and not seen before (by dfs)
// If so, we increment the total islands by 1

// Thanks to Tanishq for his solution help with the approach

class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& seen, int r, int c){
        seen[r][c] = 1; // Mark it as seen

        for(auto [dr, dc]: {pair{-1,0}, {1,0}, {0,1}, {0,-1}}){ // Coords translations (surroundings)
            int nr = r+dr, nc = c + dc;
            if(nr >= 0 && nr < grid.size() 
            && nc >= 0 && nc <grid[0].size() 
            && grid[nr][nc] == 1 && !seen[nr][nc])
                dfs(grid, seen, nr,nc);
        }
    }

    int countIslands(vector<vector<int>>& grid){
        vector<vector<int>>seen(grid.size(), vector<int>(grid[0].size(), 0));
        int islands = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && !seen[i][j]){
                    islands++;              // Increment total islands
                    dfs(grid,seen, i, j);   // Mark all surrounding 1's as seen
                }
            }
        }
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int islands = countIslands(grid);

        if(islands != 1) return 0; // If there's no island or already disconnected islands
        
        // To check whether it can be disconnected in a day
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid) != 1) return 1; // Disconnected after a single day
                    grid[i][j] = 1;  // If not, change grid back to 1
                }
            }
        }

        // Otherwise, it will be disconnected in 2 days maximum
        return 2;
    }
};