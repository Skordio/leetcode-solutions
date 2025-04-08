#include "solution.cpp"
#include <iostream>

using namespace std;

int main() 
{
    Solution sol;

    vector<vector<vector<int>>> tests;
    vector<int> answers;

    // test 1
    tests.push_back({{3, 2}, {4, 3}, {4, 4}, {2, 5}});
    answers.push_back(5);

    // test 2
    tests.push_back({{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}});
    answers.push_back(7);

    // test 3
    tests.push_back({{29, 1}, {90, 5}, {41, 5}, {46, 3}, {49, 5}, {49, 2}, {6, 5}, {36, 5}, {83, 1}, {60, 2}, {97, 3}, {54, 2}, {42, 5}, {42, 2}, {73, 4}, {38, 4}, {16, 4}, {44, 2}, {81, 2}, {76, 3}, {60, 4}, {83, 4}, {94, 2}, {13, 5}, {7, 2}, {77, 2}, {18, 2}, {91, 2}, {43, 4}, {84, 2}, {45, 1}, {42, 5}, {54, 4}, {18, 4}, {96, 5}, {44, 3}, {55, 4}, {49, 3}, {86, 2}, {41, 3}, {54, 3}, {66, 2}, {22, 3}, {35, 5}, {89, 3}, {61, 2}, {1, 3}, {72, 1}, {13, 3}, {70, 4}, {12, 4}, {35, 5}, {16, 3}, {67, 3}, {70, 3}, {5, 4}, {74, 4}, {36, 1}, {47, 2}, {72, 1}});
    answers.push_back(1113);

    for (int i = 2; i < tests.size(); i++)
    {
        int solution_answer = sol.mostPoints(tests[i]);
        int expected_answer = answers[i];

        cout << "Test " << (i + 1) << ":" << endl;
        cout << "Expected answer: " << expected_answer << endl;
        cout << "Actual answer: " << solution_answer << endl << endl;
    }

    return 0;
}