

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        if n == 0:
            return 0
        
        days = [0 for num in range(n)]
        days[0] = 1
        days[0 + forget] -= 1
        days[0 + delay] += days[0] * 

        for day in range(1, n):
            

        


        pass