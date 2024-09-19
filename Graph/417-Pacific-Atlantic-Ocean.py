class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pac, atlantic = set(), set()
        res = []

        def dfs(i, j, container, prevHeight):
            if i >= rows or i < 0 or j >= cols or j < 0 or (i, j) in container or heights[i][j] < prevHeight:
                return
            
            container.add((i, j))
            dfs(i, j + 1, container, heights[i][j])
            dfs(i, j - 1, container, heights[i][j])
            dfs(i + 1, j, container, heights[i][j])
            dfs(i - 1, j, container, heights[i][j])

        for c in range(cols):
            dfs(0, c, pac, heights[0][c])
            dfs(rows-1, c, atlantic, heights[rows-1][c])

        for r in range(rows):
            dfs(r, 0, pac, heights[r][0])
            dfs(r, cols-1, atlantic, heights[r][cols-1])

        for grid in pac:
            if grid in atlantic:
                res.append(grid)
        
        return res
        

