#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:
Input:

nums1 = [2, 4, 3]
nums2 = [5, 6, 4]
Output:

[7, 0, 8]
Explaination:
The number represented by nums1 is 342. The number represented by nums2 is 465. 342+465=807. The sum, 807, in reverse order is [7,0,8].

Example 2:
Input:

nums1 = [0]
nums2 = [0]
Output:

[0]
Explaination:
0+0=0. The sum, 0, in reverse order is [0].

Example 1:

Input:

nums1=[2,4,3] nums2=[5,6,4]

Output:

7 0 8
Explanation:342 + 465 = 807 → reversed digits [7,0,8]

Example 2:

Input:

nums1=[0] nums2=[0]

Output:

0
Explanation:0 + 0 = 0 → [0]

Example 3:

Input:

nums1=[9,9,9,9,9] nums2=[1]

Output:

0 0 0 0 0 1
Explanation:99 999 + 1 = 100 000 → reversed [0,0,0,0,0,1]

*/

class Solution
{
public:
    vector<int> addTwoNumbers(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> answer;
        int x = 0, y = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        int carry = 0;

        while (x < size1 || y < size2)
        {
            int digit1 = x < size1 ? nums1[x] : 0;
            int digit2 = y < size2 ? nums2[y] : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;

            answer.push_back(sum % 10);

            x < size1 ? x++ : x;
            y < size2 ? y++ : y;
        }

        if (carry)
            answer.push_back(carry);

        return answer;
    }
};
