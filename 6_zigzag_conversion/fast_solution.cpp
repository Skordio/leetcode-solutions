#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            vector<int> char_group_indices = {};

            int down_group_height = numRows;
            int up_group_height = numRows - 2;

            if (s.length() <= numRows) {
                char_group_indices.push_back(0);
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


            // rowNum = 0 -> s[char_group_indices[even indexes]]

            // rowNum = 1 through second to last rowNum - 
            //      s[char_group_indices[even indexes] + rowNum]
            //      s[char_group_indices[odd indexes] + up_group_height - (rowNum)]

            string out_string = "";

            for (int i = 0; i < char_group_indices.size(); i++)
            {
                if (i % 2 != 0)
                    continue;
                out_string += s[char_group_indices[i]];
            }

            for (int rowCount = 1; rowCount < (numRows - 1); rowCount++) {
                for (int i = 0; i < char_group_indices.size(); i++) {
                    if (i % 2 == 0)
                    {
                        int char_index = char_group_indices[i] + rowCount;
                        if (char_index < s.size())
                            out_string += s[char_index];
                    }
                    else
                    {
                        int char_index = char_group_indices[i] + up_group_height - (rowCount);
                        if (char_index < s.size())
                            out_string += s[char_index];
                    }

                }
            }

            for (int i = 0; i < char_group_indices.size(); i++) 
            {
                if (i % 2 != 0)
                    continue;
                out_string += s[char_group_indices[i] + (numRows-1)];
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