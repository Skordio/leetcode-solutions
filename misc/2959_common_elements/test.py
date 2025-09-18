from .sol import Solution
from typing import List

sol = Solution()


class Test:
    test_num: int
    input_vals: List[List[int]]
    correct_output: List[int]

    def __init__(self, test_num:int, input_vals: List[List[int]], correct_output: List[int]):
        self.test_num = test_num
        self.input_vals = input_vals
        self.correct_output = correct_output

    def run(self):
        answer = sol.findIntersectionValues(*self.input_vals)

        print(f"Test {self.test_num}")
        print(f"Expected: {self.correct_output}")
        print(f"Actual: {answer}\n")


def main():
    Test(1, [[2,3,2],[1,2]], [2,1]).run()
    Test(2, [[4,3,2,3,1],[2,2,5,2,3,6]], [3,4]).run()
    Test(3, [[3,4,2,3],[1,5]], [0,0]).run()
    


if __name__ == "__main__":
    main()