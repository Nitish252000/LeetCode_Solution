class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        zrow=set()
        zcol=set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]==0:
                    zrow.add(i)
                    zcol.add(j)

        for r in zrow:
            for i in range(len(matrix[0])):
                matrix[r][i]=0

        for c in zcol:
            for j in range(len(matrix)):
                matrix[j][c]=0
        
