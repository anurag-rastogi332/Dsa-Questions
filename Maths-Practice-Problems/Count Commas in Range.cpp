#include <iostream>
using namespace std;

/*

You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.


Example 1:

Input: n = 1002

Output: 3

Explanation:

The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

Example 2:

Input: n = 998

Output: 0

Explanation:

All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.



*/

class Solution
{
public:
    int countCommas(int n)
    {
        int total = 0;

        for (int i = 1; i <= n; i++)
        {
            int num = i;
            int digits = 0;

            // count digits (tumhara logic)
            while (num)
            {
                digits++;
                num /= 10;
            }

            // commas = (digits - 1) / 3
            if (digits >= 4)
            {
                total += (digits - 1) / 3;
            }
        }

        return total;
    }
};