#include <iostream>
#include <vector>

using namespace std;

void print_grid(vector<vector<char>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }
            
            int char_count = 0;
            int col = 0;
            int row = 0;
            vector<char> template_arr(s.length(), ' ');

            vector<vector<char>> grid(numRows, template_arr);

            while (char_count < s.length())
            {
                grid[row][col] = s[char_count];

                char_count++;
                row++;

                if (row == numRows) {
                    row -= 2;
                    col += 1;

                    while (row > 0 && char_count < s.length()) {
                        grid[row][col] = s[char_count];
                        char_count++;
                        row--;
                        col++;
                    }
                }
            }

            string out_string = "";

            for (row = 0;  row < grid.size(); row++)
            {
                for (col = 0;  col < grid[0].size(); col++)
                {
                    if (grid[row][col] != ' ') {
                        out_string += grid[row][col];
                    }
                }
            }

            return out_string;
        }
};

int main() 
{
    Solution sol;
    string answer = sol.convert("PAYPALISHIRING", 4);
    cout << answer << endl;

    return 0;
}