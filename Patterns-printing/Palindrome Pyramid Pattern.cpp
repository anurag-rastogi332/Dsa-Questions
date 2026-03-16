#include <iostream>
using namespace std;

/*

Multiple Example Outputs
Example 1

Input:

1

Output:

1
Example 2

Input:

2

Output:

 1
121
Example 3

Input:

3

Output:

  1
 121
12321
Example 4

Input:

4

Output:

   1
  121
 12321
1234321
Example 5

Input:

5

Output:

    1
   121
  12321
 1234321
123454321
Example 6

Input:

6

Output:

     1
    121
   12321
  1234321
 123454321
12345654321

*/

class Solution
{
public:
    void printPalindromePyramid(int N)
    {
        for (int i = 1; i <= N; i++)
        {
            // spaces
            for (int j = 1; j <= N - i; j++)
            {
                cout << " ";
            }

            // increasing numbers
            for (int j = 1; j <= i; j++)
            {
                cout << j;
            }

            // decreasing numbers
            for (int j = i - 1; j >= 1; j--)
            {
                cout << j;
            }

            cout << endl;
        }
    }
};