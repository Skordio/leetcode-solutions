#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) 
        {
            string out = "";

            vector<pair<int, string>> roman_map = {
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
            };

            for (const auto& [value, symbol] : roman_map) {
                while (num >= value) {
                    num -= value;
                    out += symbol;
                }
            }

            return out;
        }
};

int main() 
{
    Solution sol;

    // Test cases
    vector<int> test_cases = {3, 4, 9, 58, 1994};
    for (int test_num : test_cases) {
        string out = sol.intToRoman(test_num);
        cout << "Integer: " << test_num << " -> Roman: " << out << endl;
    }

    return 0;
}