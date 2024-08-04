class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rowsWrong = 0;
        int colsWrong = 0;
                
        // Loop over rows
        for(int i =0; i<grid.size(); i++)
        {
            for(int j=0, r=grid[i].size()-1; j<r ;r--, j++)
            {
                if(grid[i][j] != grid[i][r]) rowsWrong++;
            }
        }

        // Loop over columns
        for(int i =0; i<grid[0].size(); i++)
        {
            for(int j=0, r=grid.size()-1; j<r ;)
            {
                if(grid[j++][i] != grid[r--][i]) colsWrong++;
            }
        }

        return min(rowsWrong, colsWrong);
    }
};