#include "solution.cpp"
#include <iostream>

using namespace std;

int main() 
{
    Solution sol;

    vector<vector<vector<char>>> tests;
    vector<int> answers;

    // test 1
    tests.push_back({
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    });
    answers.push_back(true);


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