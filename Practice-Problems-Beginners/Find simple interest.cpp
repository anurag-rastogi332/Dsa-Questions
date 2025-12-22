#include <iostream>
using namespace std;

/*

Input
Three integers:
P → Principal amount
R → Rate of Interest (in %)
T → Time (in years)
Output
An integer or floating-point value representing the Simple Interest.
Example 1:

Input:

P=561830 R=73 T=35

Output:

14354756
Explanation:Simple Interest is calculated using the formula (P * R * T) / 100.

Example 2:

Input:

P=915546 R=1 T=60

Output:

549327
Explanation:Simple Interest is calculated using the formula (P * R * T) / 100.

Example 3:

Input:

P=872254 R=52 T=96

Output:

593246
Explanation:Simple Interest is calculated using the formula (P * R * T) / 100.

*/

class Solution
{
public:
    int simpleInterest(int P, int R, int T)
    {

        return (P * R * T) / 100;
    }
};