
#include<iostream>
using namespace std;


/*

Example
Input:

n = 4

Output:


1
2 3
4 5 6
7 8 9 10
Explanation:

The first row has 1 number: 1.
The second row has 2 numbers: 2, 3.
The third row has 3 numbers: 4, 5, 6.
The fourth row has 4 numbers: 7, 8, 9, 10.
These rows cumulatively form Floyd’s Triangle with 4 rows. The numbers continue serially across the rows, forming a smooth sequence.

Example 1:

Input:

n=1

Output:

1
Explanation:The first row of Floyd's Triangle.

Example 2:

Input:

n=2

Output:

1
2 3
Explanation:The first two rows of Floyd's Triangle.

Example 3:

Input:

n=3

Output:

1
2 3
4 5 6
Explanation:The first three rows of Floyd's Triangle.

*/

class Solution {
public:
    void printFloydsTriangle(int n) {
        // Implement the pattern printing logic here
        int count=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<count<<" ";
                count++;
            }
            cout<<endl;
        }
    }
};