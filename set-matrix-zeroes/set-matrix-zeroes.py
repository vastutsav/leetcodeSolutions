class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = set()
        cols = set()
        
        for i, r in enumerate(matrix):
            for j, c in enumerate(r):
                if c == 0:
                    rows.add(i)
                    cols.add(j)
        
        for i in rows:
            matrix[i][:] = [0] * len(matrix[0])
        
        
        
        for j in cols:
            for i in range(len(matrix)):
                matrix[i][j] = 0
                
        