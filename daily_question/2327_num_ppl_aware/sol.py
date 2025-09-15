

class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        ppl_who_know = [0 for num in range(n)]
        ppl_forget = [0 for num in range(n)]
        ppl_added = [0 for num in range(n)]

        ppl_added[0] = 1

        for day in range(0, n):
            adds_today = ppl_added[day]
            forgets_today = ppl_forget[day]

            ppl_who_know[day] += adds_today
            ppl_who_know[day] -= forgets_today

            if day+forget < n:
                ppl_forget[day + forget] = adds_today
                
            if day+delay < n:
                for add_day in range(day + delay, min(day + forget, n)):
                    ppl_added[add_day] += adds_today

            if day+1 < n:
                ppl_who_know[day+1] = ppl_who_know[day]

        
        return ppl_who_know[-1] % ((10 ** 9) + 7)
        