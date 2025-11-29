// main method
// very important question for amazon,flipcart,microsoft,google

/*

Example:
Example 1:
Input: x = 16

Output: 4

Explanation: The integer part of the square root of 16 is 4 since 4 * 4 = 16.

Example 2:
Input: x = 8

Output: 2

Explanation: The integer part of the square root of 8 is 2 since 3 * 3 = 9 (which is greater than 8), and 2 * 2 = 4, which is less than 8.

Example 1:

Input:

Input: x = 0

Output:

0
Explanation:

Example 2:

Input:

Input: x = 1

Output:

1
Explanation:

Example 3:

Input:

Input: x = 4

Output:

2
Explanation:

*/

class Solution
{
public:
    bool checlValidAnswer(long long product, int target)
    {
        if (product == target)
            return true;
        else
            return false;
    }

    int mySqrt(int x)
    {
        // Implement the logic for calculating sqrt using binary search
        int target = x;
        int s = 0;
        int e = target;
        int ans = -1;

        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            long long int product = mid * mid;
            // check mid
            if (checlValidAnswer(product, target))
            {
                return mid;
            }
            // left
            if (product > target)
            {
                e = mid - 1;
            }
            // right
            if (product < target)
            {
                // store the mid
                ans = mid;

                s = mid + 1;
            }
        }

        return ans;
    }
};

/*
important note:-

search space reduction technique
binary search ke advanced questions isi technique per based hote hai like book allocation, eco spoch, roti paratha spoch
mid ko check krne ke liye ek alag se function likha jata hai jise hum predicate function kehte hai

*/

/*

 =================== BINARY SEARCH ON ANSWER (SHORT NOTES) ===================

 1) Use when array me search nahi karna hota,
    balki answer ek RANGE me hota hai (0..10^9 type).

 2) Is technique ka naam:
    - Search Space Reduction
   - Solution Space Reduction
   - Binary Search on Answer

 3) Advanced problems isi par based:
    Book Allocation, Aggressive Cows, Roti-Paratha,
    ECO-SPOJ, Koko Bananas, Painter Partition, Shipping Capacity.

 4) Logic:
    - Search space choose karo (s, e)
    - mid = possible answer
    - mid ko check karne ke liye PREDICATE FUNCTION banao

 5) Predicate Function:
    - Returns TRUE → mid ek valid answer ho sakta hai
    - Returns FALSE → mid invalid → search adjust

6) Very important:
    if (predicate(mid) == true)
         answer = mid; e = mid - 1;   // minimize answer
    else
        s = mid + 1;

7) Predicate function names:
    - isPossible()
    - canDo()
    - isValid()
    - check()
    - feasible()

 8) End:
    - Loop ke baad 'answer' hi final hoga.
 ==============================================================================



*/