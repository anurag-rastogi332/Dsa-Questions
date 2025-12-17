#include <iostream>
using namespace std;

/*

Given two numbers a and b. The task is to find out their LCM.


Examples:

Input: a = 5, b = 10
Output: 10
Explanation: LCM of 5 and 10 is 10
Input: a = 14, b = 8
Output: 56
Explanation: LCM of 14 and 8 is 56

*/

// User function Template for C++

// first code->

int LCM(int a, int b)
{

    // write your code here

    // return LCM of a and b

    int l;
    if (a > b)
        l = a;
    else
        l = b;
    int r = a * b;

    for (int i = l; i <= r; i++)
    {
        if (i % a == 0 && i % b == 0)
        {
            return i;
        }
    }
    return a * b;
}

// second code ->

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

int LCM(int a, int b)
{

    int ans = (a * b) / gcd(a, b);

    return ans;
}