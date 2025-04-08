#include <vector>

class Solution {
public:
    long long mostPoints(std::vector<std::vector<int>>& questions) {
        int n = questions.size();
        std::vector<long long> max_starting_at(n + 1, 0); 

        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int skip = questions[i][1];

            long long solve = points + (i + skip + 1 < n ? max_starting_at[i + skip + 1] : 0);

            long long skip_q = max_starting_at[i + 1];

            max_starting_at[i] = std::max(solve, skip_q);
        }

        return max_starting_at[0];
    }
};