class NumMatrix:

    def __init__(self, matrix: list[list[int]]):
        rows = len(matrix)
        cols = len(matrix[0])

        self.m = [[0] * cols for n in range(rows)]

        self.m[0][0] = matrix[0][0]

        for i in range(rows):
            self.m[i][0] = matrix[i][0]

        for i in range(rows):
            for j in range(1, cols):
                self.m[i][j] = self.m[i][j - 1] + matrix[i][j]

        for i in range(1, rows):
            for j in range(cols):
                self.m[i][j] += self.m[i - 1][j]

        print(self.m)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = self.m[row2][col2]
        if row1 > 0:
            ans -= self.m[row1 - 1][col2]
        if col1 > 0:
            ans -= self.m[row2][col1 - 1]
        if row1 > 0 and col1 > 0:
            ans += self.m[row1 - 1][col1 - 1]

        return ans


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)