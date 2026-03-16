#include <iostream>
using namespace std;

// Names-> Symmetric Consecutive Number Pattern,Number Hourglass Pattern,Symmetric Consecutive Number Pattern,palindromic mirrored triangle,diamond of consecutive numbers with * separators

/*

First understand the given output

From the image, the pattern is:

1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1

So this is:

numbers are continuous

each row has increasing count first

then same rows come back in reverse

middle row is repeated

Multiple example outputs
Example 1: N = 1
1
1

Because only one row exists, and middle repeats.

Example 2: N = 2
1
2*3
2*3
1
Example 3: N = 3
1
2*3
4*5*6
4*5*6
2*3
1
Example 4: N = 4
1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1
Example 5: N = 5
1
2*3
4*5*6
7*8*9*10
11*12*13*14*15
11*12*13*14*15
7*8*9*10
4*5*6
2*3
1
Example 6: N = 6
1
2*3
4*5*6
7*8*9*10
11*12*13*14*15
16*17*18*19*20*21
16*17*18*19*20*21
11*12*13*14*15
7*8*9*10
4*5*6
2*3
1

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int c = 1;

    // Growing phase
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << c;
            c++;

            if (j < i)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    // Shrinking phase
    int start = c - n;

    for (int i = 0; i < n; i++)
    {
        int k = start;

        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << k;
            k++;

            if (j < n - i - 1)
            {
                cout << "*";
            }
        }

        start = start - (n - i - 1);
        cout << endl;
    }

    return 0;
}
