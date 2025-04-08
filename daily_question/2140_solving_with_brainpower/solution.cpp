#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        vector<pair<int, int>> solutions = {{0,0}};
        for (vector<int> question : questions)
        {
            vector<pair<int, int>> new_solutions;

            int score = question[0];
            int skips = question[1];

            // further each branch

            for (int i = 0; i < solutions.size(); i++)
            {
                if(solutions[i].second == 0) {                
                    new_solutions.push_back({solutions[i].first + score, solutions[i].second + skips});
                } 
                else {
                    solutions[i].second -= 1;
                }
            }

            solutions.insert(solutions.end(), new_solutions.begin(), new_solutions.end());

            // prune solutions

            unordered_map<int, vector<int>> solutions_for_num_skips;

            for (int i = 0; i < solutions.size(); i++)
            {
                int skip_amount = solutions[i].second;
                solutions_for_num_skips[skip_amount].push_back(i);
            }

            for (const auto& pair : solutions_for_num_skips)
            {
                int skip_amount = pair.first;
                vector<int> indices = pair.second;

                if(indices.size() > 1) {
                    int highest_score = 0;
                    int highest_index = 0;

                    for (int index : indices) {
                        int score = solutions[index].first;

                        if (score >= highest_score) {
                            highest_index = index;
                            highest_score = score;
                        }
                    }

                    for (int i = indices.size() - 1; i >= 0; i--) {
                        if (pair.second[i] == highest_index)
                            continue;
                        solutions.erase(solutions.begin() + pair.second[i]);
                    }
                }
            }
        }

        long best_score = 0;

        for(pair<int, int> solution : solutions)
        {
            if(solution.first > best_score)
            {
                best_score = solution.first;
            }
        }

        return best_score;
    }
};
