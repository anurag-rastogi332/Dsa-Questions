#include <iostream>
using namespace std;

/*

Multiple Examples
Example 1

Input:

1
7 @

Output:

@@@@@@@
 @@@@@
  @@@
   @
  @@@
 @@@@@
@@@@@@@

Example 2

Input:

1
5 *

Output:

*****
 ***
  *
 ***
*****

Example 3

Input:

1
3 +

Output:

+++
 +
+++

Example 4

Input:

1
1 X

Output:

X

Example 5

Input:

1
9 #

Output:

#########
 #######
  #####
   ###
    #
   ###
  #####
 #######
#########


*/

class Solution
{
public:
    void printHourglass(int N, char C)
    {
        int spaces = 0;
        int chars = N;

        // Upper part
        while (chars >= 1)
        {
            for (int i = 0; i < spaces; i++)
            {
                cout << " ";
            }

            for (int i = 0; i < chars; i++)
            {
                cout << C;
            }

            cout << endl;
            spaces++;
            chars -= 2;
        }

        // Lower part
        spaces = N / 2 - 1;
        chars = 3;

        while (chars <= N)
        {
            for (int i = 0; i < spaces; i++)
            {
                cout << " ";
            }

            for (int i = 0; i < chars; i++)
            {
                cout << C;
            }

            cout << endl;
            spaces--;
            chars += 2;
        }
    }
};
