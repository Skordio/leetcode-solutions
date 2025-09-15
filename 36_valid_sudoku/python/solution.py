from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # empty squares are denoted by periods

        squares = [[[], [], []], [[], [], []], [[], [], []]]
        rows = [[] for num in range(0,9)]
        cols = [[] for num in range(0,9)]

        # check rows
        for row in range(0, 9):
            for col in range(0, 9):
                num = board[row][col]

                if rows[row].count(num) != 0:
                    return False
                elif cols[col].count(num) != 0:
                    return False
                elif squares[row // 3][col // 3].count(num) != 0:
                    return False
                
                rows[row].append(num)
                cols[col].append(num)
                squares[row // 3][col // 3].append(num)

        return True

