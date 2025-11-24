
#include<iostream>
using namespace std;

/*

Example
For instance, if the input n is 5, the expected output should be:


A
AB
ABC
ABCD
ABCDE
This illustrates a triangle with 5 rows, where each row begins with the letter 'A' and extends through the i-th letter of the alphabet for that row number, where i is the row index starting from 1.

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

A
AB
Explanation:A triangle with two rows.

Example 3:

Input:

n=3

Output:

A
AB
ABC
Explanation:A triangle with three rows.

*/


class Solution {
public:
    void printAlphabetTriangle(int n) {
        // Implement the pattern printing logic here
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                cout<<char('A'+j);
            }
            cout<<endl;
        }
    }
};