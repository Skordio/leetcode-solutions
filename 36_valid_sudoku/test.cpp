#include "solution.cpp"
#include <iostream>

using namespace std;

int main() 
{
    Solution sol;

    vector<vector<vector<char>>> tests;
    vector<int> answers;

    // test 1
    tests.push_back({{'1'}});
    answers.push_back(false);


    for (int i = 0; i < tests.size(); i++)
    {
        int solution_answer = sol.isValidSudoku(tests[i]);
        int expected_answer = answers[i];

        cout << "Test " << (i + 1) << ":" << endl;
        cout << "Expected answer: " << expected_answer << endl;
        cout << "Actual answer: " << solution_answer << endl << endl;
    }

    return 0;
}