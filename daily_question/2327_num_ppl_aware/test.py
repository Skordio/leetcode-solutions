from .sol import Solution

sol = Solution()

class Test:
    n:int
    delay:int
    forget:int
    expected_output:int

    def __init__(self, n:int, delay:int, forget:int, expected_output:int):
        self.n = n
        self.delay = delay
        self.forget = forget
        self.expected_output = expected_output

    def run(self):
        output = sol.peopleAwareOfSecret(self.n, self.delay, self.forget)

        print(f"Expected output: {self.expected_output}")
        print(f"Actual Output: {output}")
        print()


def main():
    Test(6, 2, 4, 5).run()
    
    
if __name__ == "__main__":
    main()