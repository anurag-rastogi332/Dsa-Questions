#include <iostream>
using namespace std;

/*

Example 1:

Input:

a=3 b=7 c=5

Output:

7
Explanation:Among the three numbers 3, 7, and 5, the maximum is 7.

Example 2:

Input: a=-327266113 b=-931480897 c=654747322

Output: '654747322'

Explanation: Among the numbers -327266113, -931480897, and 654747322, the maximum is 654747322.

Example 3:

Input: a=-861733977 b=65034374 c=580274960

Output: '580274960'

Explanation: Among the numbers -861733977, 65034374, and 580274960, the maximum is 580274960.

*/

class Solution
{
public:
    int maxi(int a, int b, int c)
    {
        if (a > b && a > c)
            return a;
        else if (b > a && b > c)
            return b;
        else
            return c;
    }
};