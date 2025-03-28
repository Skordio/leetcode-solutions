#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            vector<tuple<int, int>> char_groups = {};

            if (s.length() <= numRows) {
                char_groups.push_back(make_tuple(0, s.length()));
            } else {
                int index = 0;
                int end_index = 0;
                while (index < s.length()) {
                    end_index = index + numRows;
                    // Down group
                    char_groups.push_back(make_tuple(index, index + numRows));

                    index = end_index;
                    end_index = index + (numRows - 2);

                    //Up group
                    char_groups.push_back(make_tuple(index, index + (numRows - 2)));

                    index = end_index;
                }

            }

            string out_string = "";

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