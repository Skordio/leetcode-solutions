#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            string outstring = "";
            while (num >= 1000)
            {
                num = num - 1000;
                outstring += "M";
            }
        }
        
};

int main() 
{

}