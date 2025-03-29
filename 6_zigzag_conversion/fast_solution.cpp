#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }

            vector<int> char_group_indices = {};

            int down_group_height = numRows;
            int up_group_height = numRows - 2;

            if (s.length() <= numRows) {
                return s;
            } else {
                int index = 0;
                while (index < s.length()) {
                    // Down group
                    char_group_indices.push_back(index);

                    index = index + down_group_height;

                    if (!(index < s.length()))
                        break;

                    //Up group
                    char_group_indices.push_back(index);

                    index = index + up_group_height;
                }
            }

            string out_string = "";

            for (int i = 0; i < char_group_indices.size(); i++)
            {
                if (i % 2 == 0 && char_group_indices[i] < s.size())
                    out_string += s[char_group_indices[i]];
            }

            for (int rowCount = 1; rowCount < (numRows - 1); rowCount++) {
                for (int i = 0; i < char_group_indices.size(); i++) {
                    int char_index;

                    if (i % 2 == 0)
                        char_index = char_group_indices[i] + rowCount;
                    else
                        char_index = char_group_indices[i] + up_group_height - (rowCount);

                    if (char_index < s.size())
                        out_string += s[char_index];
                }
            }

            for (int i = 0; i < char_group_indices.size(); i++) 
            {
                int char_index = char_group_indices[i] + (numRows - 1);
                if (i % 2 == 0 && char_index < s.size())
                    out_string += s[char_index];
            }

            return out_string;
        }
};

int main() 
{
    Solution sol;
    string answer = sol.convert("PAYPALISHIRING", 3);
    cout << answer << endl;

    return 0;
}