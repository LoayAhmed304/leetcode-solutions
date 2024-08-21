class Solution {
public:
    bool backtrack(vector<vector<char>>&board, string& word, int r, int c, int i){
        if(r>=board.size() || r<0 || c>=board[0].size() || c<0 || board[r][c] != word[i])
            return false;

        if(i >= word.size()-1) return true;
        board[r][c] = '#';

        // 4 Directions
        if(backtrack(board, word, r+1, c, i+1)
        || backtrack(board, word, r-1, c, i+1)
        || backtrack(board, word, r, c+1, i+1)
        || backtrack(board, word, r, c-1, i+1))
            return true;
        
        board[r][c] = word[i];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i =0; i<rows; i++){
            for(int j =0; j<cols; j++){
                if(board[i][j] == word[0])
                    if(backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
