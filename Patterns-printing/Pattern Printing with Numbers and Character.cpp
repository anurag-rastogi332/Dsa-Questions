#include <iostream>
using namespace std;

/*

Given an integer n and a character C, print a pattern of n rows.
In the i-th row (1-based indexing), print the number i exactly i times in alternating positions so that the pattern forms a centered triangle. Fill all the remaining positions with the character C.

The total width of the pattern should be 2*n - 1.

Examples
Input:
n = 5, C = '*'
Output:
****1****
***2*2***
**3*3*3**
*4*4*4*4*
5*5*5*5*5
Input:
n = 4, C = '#'
Output:
###1###
##2#2##
#3#3#3#
4#4#4#4

*/

class Solution
{
public:
    void printPattern(int n, char C)
    {
        for (int i = 0; i < n; i++)
        {
            int startNumIndex = 8 - i;
            int num = i + 1;
            int countNum = num;

            for (int j = 0; j < 17; j++)
            {
                if (j == startNumIndex && countNum > 0)
                {
                    cout << num;
                    startNumIndex += 2;
                    countNum--;
                }
                else
                {
                    cout << "*";
                }
            }
            cout << endl;
        }
    }
};