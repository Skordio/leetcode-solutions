#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Columns
            for (int col = 0; col < 9; col++) {
                int appearances[9] = {0,0,0,0,0,0,0,0,0};

                for (int row = 0; row < 9; row++) {
                    if (board[row][col] == '.')
                        continue;
                    int number = (board[row][col] - '0') - 1;
                    appearances[number]++;
                    cout << (board[row][col] - '0') << endl;
                    if (appearances[number] > 1) {
                        return false;
                    }
                }
            }

            //Rows
            for (int row = 0; row < 9; row++) {
                int appearances[9] = {0,0,0,0,0,0,0,0,0};

                for (int col = 0; col < 9; col++) {
                    if (board[row][col] == '.')
                        continue;
                    int number = (board[row][col] - '0') - 1;
                    appearances[number]++;
                    cout << (board[row][col] - '0') << endl;
                    if (appearances[number] > 1) {
                        return false;
                    }
                }
            }

            return true;
        }
    };