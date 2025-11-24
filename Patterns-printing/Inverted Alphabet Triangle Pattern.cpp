
#include<iostream>
using namespace std;




/*

Example
For n = 5, the expected output is:


ABCDE
ABCD
ABC
AB
A
Here, each row in the resulting pattern decreases by one letter until only 'A' remains in the final row.

This task involves generating and printing this pattern based on the provided input value n.

Example 1:

Input:

n=1

Output:

A
Explanation:A single row with 'A'.

Example 2:

Input:

n=2

Output:

AB
A
Explanation:An inverted triangle with two rows.

Example 3:

Input:

n=3

Output:

ABC
AB
A
Explanation:An inverted triangle with three rows.

*/

class Solution {
public:
    void printInvertedAlphabetTriangle(int n) {
        // Implement the pattern printing logic here
        for(int i=n;i>=1;i--){
            for (int j = 0; j < i; j++) {
                cout << char('A' + j);
            }
            cout<<endl;
        }
    }
};