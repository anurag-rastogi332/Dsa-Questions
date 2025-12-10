#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

Example:
Example 1:
Input: ['h', 'e', 'l', 'l', 'o']
Output: ['o', 'l', 'l', 'e', 'h']
Example 2:
Input: ['A', 'B', 'C', 'D']
Output: ['D', 'C', 'B', 'A']
Note:

The array can contain both uppercase and lowercase characters.
It's important to swap elements within the array to reverse it without using additional space.
Example 1:

Input:

Input: ['a', 'b', 'c', 'd', 'e']

Output:

e,d,c,b,a
Explanation:Reversing ['a', 'b', 'c', 'd', 'e'] results in ['e', 'd', 'c', 'b', 'a'].

Example 2:

Input:

Input: ['x', 'y', 'z']

Output:

z,y,x
Explanation:Reversing ['x', 'y', 'z'] results in ['z', 'y', 'x'].

Example 3:

Input:

Input: ['1', '2', '3', '4', '5', '6']

Output:

6,5,4,3,2,1
Explanation:Reversing ['1', '2', '3', '4', '5', '6'] results in ['6', '5', '4', '3', '2', '1'].

*/

class Solution {
public:
  void reverseCharArray(vector<char> &arr) {
     reverse(arr.begin(), arr.end()); 
     }
};