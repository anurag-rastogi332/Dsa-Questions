#include <iostream>
using namespace std;

/*

Example:
Input:

n = 5

Output:

5

Explanation:

F(0) = 0
F(1) = 1
F(2) = F(1) + F(0) = 1
F(3) = F(2) + F(1) = 2
F(4) = F(3) + F(2) = 3
F(5) = F(4) + F(3) = 5
So, the 5th Fibonacci number is 5.

Example 1:

Input:

Input: n = 0

0
Explanation:Fibonacci(0) = 0.

Example 2:

Input:

Input: n = 1

Output:

1
Explanation:Fibonacci(1) = 1.

Example 3:

Input:

Input: n = 2

Output:

1
Explanation:Fibonacci(2) = Fibonacci(1) + Fibonacci(0) = 1 + 0 = 1.

*/
class Fibonacci
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
};