class Solution {
public:
    bool isValid(vector<vector<int>>& matrix, int left, int up){
        int rowSum = matrix[left][up] + matrix[left][up+1] + matrix[left][up+2];
        int diagonalSum = matrix[left][up] + matrix[left+1][up+1] + matrix[left+2][up+2];
        int diagonal2Sum = matrix[left+2][up] + matrix[left+1][up+1] + matrix[left][up+2];

        if(diagonalSum != rowSum || diagonal2Sum != diagonalSum) return false;
        unordered_map<int, int>mp;

        // Calculate occurence
        for(int i = left; i< left + 3; i++){
            for(int j = up; j< up + 3; j++){
                mp[matrix[i][j]]++;
                if(matrix[i][j] > 9 || matrix[i][j] == 0 || mp[matrix[i][j]] > 1) return false;
            }
        }

        // Calculate rows sum
        for(int i =left; i<left+3; i++){
            int curSum = 0;
            for(int j=up; j<up+3; j++){
                curSum  += matrix[i][j];
            }
            if(curSum != rowSum) return false;
        }

        // Calculate columns sum
        for(int i =up; i<up+3; i++){
            int curSum = 0;
            for(int j=left; j<left+3; j++){
                curSum  += matrix[j][i];
            }
            if(curSum != rowSum) return false;
        }        

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
     int up = 0, left=0;
     int res=0;
     int rows = grid.size();
     int cols = grid[0].size();

     while(up < cols-2){
        left = 0;
        while(left < rows-2){
            if(isValid(grid, left, up)) res++;
            left++;
        }
        up++;
     }
     return res;
    }
};