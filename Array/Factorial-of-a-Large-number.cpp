#include <iostream>
#include <vector>
using namespace std;

// gfg->https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

/*

Your task is to implement the function to compute the factorial of N as a string.

Example 1:

Input:

N = 0

Output:

1
Explanation:By definition, the factorial of 0 equals 1.

Example 2:

Input:

N = 1

Output:

1
Explanation:1! = 1.

Example 3:

Input:

N = 2

Output:

2
Explanation:2! = 2 × 1 = 2.

*/

#include <algorithm>
class Solution
{
public:
    void reverseVector(vector<int> &fact)
    {
        int left = 0;
        int right = fact.size() - 1;

        while (left < right)
        {
            int temp = fact[left];
            fact[left] = fact[right];
            fact[right] = temp;
            left++;
            right--;
        }
    }

    
    string factorial(int N)
    {
        vector<int> fact;
        fact.push_back(1);

        for (int i = 2; i <= N; i++)
        {

            int carry = 0;

            for (int j = 0; j < fact.size(); j++)
            {
                int product = fact[j] * i;
                product += carry;
                carry = product / 10;
                fact[j] = product % 10;
            }

            if (carry)
            {
                while (carry)
                {
                    fact.push_back(carry % 10);
                    carry /= 10;
                }
            }
        }

        reverseVector(fact);

        string ans = "";
        for (int i = 0; i < fact.size(); i++)
        {
            ans += (fact[i] + '0');
        }

        return ans;
    }
};