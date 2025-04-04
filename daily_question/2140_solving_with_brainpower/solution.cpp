#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        vector<pair<int, int>> solutions = {{0,0}};
        for (vector<int> question : questions)
        {
            int score = question[0];
            int skips = question[1];

            // print thingy
            cout << "[" << score << ", " << skips << "]" << endl;
        }

        return 0;
    }
};

int main() 
{
    Solution sol;

    vector<vector<int>> test1 = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};

    sol.mostPoints(test1);

    return 0;
}