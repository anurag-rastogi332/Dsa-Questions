


#include<iostream>
using namespace std;

/*

Example
For instance, let n = 3:

The pattern should be:


  *
 ***
*****
 ***
  *
This pattern reflects a diamond shape with the widest point being the third row, consisting of 5 '*', then tapering down symmetrically. Your task is to produce such a pattern for any valid integer input n between 1 and 20.

Example 1:

Input:

n=1

Output:

*
Explanation:A single row with one '*' as n=1.

Example 2:

Input:

n=2

Output:

 *
***
 *
Explanation:Diamond pattern with height 3 rows when n=2.

Example 3:

Input:

n=3

Output:

  *
 ***
*****
 ***
  *
Explanation:Diamond pattern with height 5 rows when n=3.

*/


class Solution {
public:
    void printSolidDiamond(int n) {
        // Implement the pattern printing logic here
        for(int row=1; row<=n;row++){
            for(int colm=1;colm<=n-row;colm++){
                cout<<" ";

            }
            for(int colm=1;colm<=(2*row)-1;colm++ ){
                cout<<"*";
            }
            cout<<endl;
        }
        n--;
        for(int row=1;row<=n;row++){
            for(int colm=1; colm<=row;colm++){
                cout<<" ";
            }
            for(int colm=1;colm<=(2*n)-(2*row)+1; colm++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
};