#include <iostream>
using namespace std;

/*

Examples:

Input: a = 20, b = 28
Output: 4
Explanation: GCD of 20 and 28 is 4
Input: a = 60, b = 36
Output: 12
Explanation: GCD of 60 and 36 is 12

*/

// this code submited in gfg without time limit exceed

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }

        return a == 0 ? b : a;
    }
};

// this code not submit in gfg platform due to time limit exceed
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }

        return a == 0 ? b : a;
    }
};

// this code not submit in gfg platform due to time limit exceed
class Solution
{
public:
    int gcd(int a, int b)
    {

        int l = min(a, b);

        for (int i = l; i >= 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                return i;
            }
        }

        return 1;
    }
};
