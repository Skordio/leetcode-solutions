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

int main() 
{
    Solution sol;

    vector<vector<int>> test1 = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};

    cout << sol.mostPoints(test1) << endl;

    vector<vector<int>> test2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

    cout << sol.mostPoints(test2) << endl;

    vector<vector<int>> test3 = {{29, 1}, {90, 5}, {41, 5}, {46, 3}, {49, 5}, {49, 2}, {6, 5}, {36, 5}, {83, 1}, {60, 2}, {97, 3}, {54, 2}, {42, 5}, {42, 2}, {73, 4}, {38, 4}, {16, 4}, {44, 2}, {81, 2}, {76, 3}, {60, 4}, {83, 4}, {94, 2}, {13, 5}, {7, 2}, {77, 2}, {18, 2}, {91, 2}, {43, 4}, {84, 2}, {45, 1}, {42, 5}, {54, 4}, {18, 4}, {96, 5}, {44, 3}, {55, 4}, {49, 3}, {86, 2}, {41, 3}, {54, 3}, {66, 2}, {22, 3}, {35, 5}, {89, 3}, {61, 2}, {1, 3}, {72, 1}, {13, 3}, {70, 4}, {12, 4}, {35, 5}, {16, 3}, {67, 3}, {70, 3}, {5, 4}, {74, 4}, {36, 1}, {47, 2}, {72, 1}};

    int expected = 1113;

    cout << sol.mostPoints(test3) << endl;

    return 0;
}