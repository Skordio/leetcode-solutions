#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long mostPoints(std::vector<std::vector<int>>& questions)
    {
        std::vector<std::pair<int, int>> solutions = {{0,0}};
        for (std::vector<int> question : questions)
        {
            std::vector<std::pair<int, int>> new_solutions;
            std::unordered_map<int, std::vector<int>> solutions_for_num_skips;

            int score = question[0];
            int skips = question[1];

            // further each branch

            for (int i = 0; i < solutions.size(); i++)
            {
                if(solutions[i].second == 0) {                
                    new_solutions.push_back({solutions[i].first + score, skips});
                    solutions_for_num_skips[skips].push_back(solutions.size() - 1 + new_solutions.size());
                    solutions_for_num_skips[0].push_back(i);
                } 
                else {
                    solutions[i].second -= 1;
                    solutions_for_num_skips[solutions[i].second].push_back(i);
                }
            }

            solutions.insert(solutions.end(), new_solutions.begin(), new_solutions.end());

            // prune solutions

            std::vector<int> erase_indices;

            for (const auto& pair : solutions_for_num_skips)
            {
                int skipamt = pair.first;
                std::vector<int> indices_with_skipamt = pair.second;

                if(indices_with_skipamt.size() > 1) {
                    int highest_score = 0;
                    int highest_index = 0;

                    for (int index : indices_with_skipamt) {
                        int score = solutions[index].first;

                        if (score >= highest_score) {
                            highest_index = index;
                            highest_score = score;
                        }
                    }

                    for (int i = indices_with_skipamt.size() - 1; i >= 0; i--) {
                        if (pair.second[i] == highest_index)
                            continue;
                        erase_indices.push_back(pair.second[i]);
                    }
                }
            }

            std::sort(erase_indices.begin(), erase_indices.end());

            for (int i = erase_indices.size() - 1; i >= 0; i--)
            {
                solutions.erase(solutions.begin() + erase_indices[i]);
            }
        }

        long best_score = 0;

        for(std::pair<int, int> solution : solutions)
        {
            if(solution.first > best_score)
            {
                best_score = solution.first;
            }
        }

        return best_score;
    }
};
