

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        if n == 0:
            return 0
        
        ppl_who_know = [0 for num in range(n)]
        forget_ppl = [0 for num in range(n)]
        add_ppl = [0 for num in range(n)]

        add_ppl[0] = 1

        for day in range(0, n):
            adds_today = add_ppl[day]
            forgets_today = forget_ppl[day]

            ppl_who_know[day] += adds_today
            ppl_who_know[day] -= forgets_today

            if day+forget < n:
                forget_ppl[day + forget] = adds_today
                
            if day+delay < n:
                for add_day in range(day + delay, min(day + forget, n)):
                    add_ppl[add_day] += adds_today

            if day+1 < n:
                ppl_who_know[day+1]
        
        return ppl_who_know[-1]
            

                

        


        pass