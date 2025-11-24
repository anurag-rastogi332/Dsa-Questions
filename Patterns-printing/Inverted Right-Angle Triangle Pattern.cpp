

#include<iostream>
using namespace std;


/*

Example:
If the input n is 4, your output should be:


* * * * 
* * * 
* * 
* 
Explanation:
Row 1 has 4 asterisks, each followed by a space.
Row 2 has 3 asterisks, each followed by a space.
Row 3 has 2 asterisks, each followed by a space.
Row 4 has 1 asterisk followed by a space.
Example 1:

Input:

n=2

Output:

* * 
* 
Explanation:An inverted right-angle triangle pattern of height 2.

Example 2:

Input:

n=3

Output:

* * * 
* * 
* 
Explanation:An inverted right-angle triangle pattern of height 3.

Example 3:

Input:

n=5

Output:

* * * * * 
* * * * 
* * * 
* * 
* 
Explanation:An inverted right-angle triangle pattern of height 5.

*/


class Solution {
public:
    void printInvertedRightAngleTriangle(int n) {
        // Implement the pattern printing logic here
        for(int row=0;row<n;row++){
            for(int colm=0;colm<(n-row);colm++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};