#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<char>> convert(string s, int numRows) {
            int char_count = 0;
            int col = 0;
            int row = 0;
            vector<char> template_arr(s.length(), ' ');

            vector<vector<char>> grid(3, template_arr);

            while (char_count < s.length())
            {
                grid[row][col] = s[char_count];

                char_count++;
                row++;

                if (row == numRows) {
                    row -= 2;
                    col += 1;

                    while (row > 0) {
                        grid[row][col] = s[char_count];
                        char_count++;
                        row--;
                        col++;
                    }
                }
            }

            return grid;
        }

        void print_grid(vector<vector<char>> grid) {
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() 
{
    Solution sol;
    vector<vector<char>> grid = sol.convert("PAYPALISHIRING", 3);
    sol.print_grid(grid);

    return 0;
}