class Solution:
    def solve(self, board: List[List[str]]) -> None:
        def dfs(board: List[List[str]], i, j) -> None:
            if i not in range(len(board)) or j not in range(len(board[0])):
                return
            if board[i][j] == 'X' or board[i][j] == 'T':
                return
            
            board[i][j] = 'T'
            dfs(board, i, j-1) # Left
            dfs(board, i-1, j) # Up
            dfs(board, i, j+1) # Right
            dfs(board, i+1, j) # Down
        rows = len(board)
        cols = len(board[0])

        # Left and right bounds
        for i in range(rows):
            if board[i][0] == 'O':
                dfs(board, i, 0)
            if board[i][cols-1] == 'O':
                dfs(board, i, cols-1)
        
        # Upper and lower bounds
        for i in range(cols):
            if board[0][i] == 'O':
                dfs(board, 0, i)
            if board[rows-1][i] == 'O':
                dfs(board, rows - 1, i)
        
        # Loop over all the grid and flip the marks
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'T':
                    board[i][j] = 'O'
                    continue
                if board[i][j] == 'O':
                    board[i][j] = 'X'
        
