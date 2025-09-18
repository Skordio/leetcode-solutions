from .solution import Solution
from typing import List

sol = Solution()

class Test:
    board: List[List[str]]
    expected_output: bool
    test_num: int

    def __init__(self, board, expected_output, test_num):
        self.board = board
        self.expected_output = expected_output
        self.test_num = test_num

    def run(self):
        output = sol.isValidSudoku(self.board)

        print(f"Test {self.test_num}")
        print(f"Expected output is: {self.expected_output}")
        print(f"Actual output is: {output}")

def main():
    board = \
        [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Test(board, True, 1).run()

    board = \
        [["8","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Test(board, False, 2).run()

if __name__ == "__main__":
    main()