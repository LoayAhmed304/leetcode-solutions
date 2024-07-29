class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bot = rows - 1;

        while(top <= bot)
        {
            int midRow = (top+bot)/2;

            if(target > matrix[midRow][cols-1])
                top = midRow + 1;
            else if(target < matrix[midRow][0])
                bot = midRow - 1;
            else
                break;
        }

        if(!(top <= bot))
            return false;
        
        int row = (top + bot) / 2;
        int l =0, r = cols - 1;

        while(l<=r){
            int mid = (l+r)/2;
            if(target > matrix[row][mid])
                l = mid+1;
            else if(target < matrix[row][mid])
                r = mid-1;
            else
                return true;
        }
        return false;
    }
};
