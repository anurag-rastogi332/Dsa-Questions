#include <iostream>
using namespace std;

/*

Input format
A single integer n.

Output format
Print Yes if the number is prime, otherwise print No.

Example 1:

Input:

n=336366944

Output:

No
Explanation:336366944 is divisible by a number other than 1 and itself, so it is not a prime number.

Example 2:

Input:

n=34259552

Output:

No
Explanation:34259552 is divisible by a number other than 1 and itself, so it is not a prime number.

Example 3:

Input:

n=827373662

Output:

No
Explanation:827373662 is divisible by a number other than 1 and itself, so it is not a prime number.

*/

class Solution
{
public:
    string isPrime(int n)
    {
        if (n == 0 || n == 1)
            return "No";

        for (int i = 2; i < n; i++)
        {
            if ((n % i) == 0)
            {
                return "No";
            }
        }
        //  “Agar √n tak koi factor nahi mila, to n prime hai.”
        return "Yes";
    }
};
