class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = -1, numberFresh = 0;
        int EMPTY = 0, FRESH = 1, ROTTEN = 2; // Values meanings
        int rows = grid.size(), cols = grid[0].size();

        // Count fresh and insert rottens into queue
        for(int i = 0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(grid[i][j] == FRESH) {
                    ++numberFresh;
                }else if (grid[i][j] == ROTTEN){
                    q.push({i, j});
                }
            }
        }
        
        // If they're all rotten or empty grid
        if(numberFresh == 0) return 0;

        while(!q.empty()){
            int size = q.size();
            for(int k =0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // UP
                if(i - 1 >= 0 && grid[i-1][j] == FRESH){
                    grid[i-1][j] = ROTTEN;
                    numberFresh--;
                    q.push({i-1, j});
                }

                // DOWN
                if(i + 1 < rows && grid[i+1][j] == FRESH){
                    grid[i+1][j] = ROTTEN;
                    numberFresh--;
                    q.push({i+1, j});
                }

                // LEFT
                if(j - 1 >= 0 && grid[i][j - 1] == FRESH){
                    grid[i][j - 1] = ROTTEN;
                    numberFresh--;
                    q.push({i, j - 1});
                }

                // RIGHT
                if(j + 1 < cols && grid[i][j + 1] == FRESH){
                    grid[i][j + 1] = ROTTEN;
                    numberFresh--;
                    q.push({i, j + 1});
                }
            }
            ++time;
        }
        return numberFresh == 0 ? time : -1;
    }
};
