
#include<iostream>
using namespace std;


/*

Example
Suppose you are given n = 4. The rhombus pattern will be generated as follows:


            * * * * 
        * * * * 
    * * * * 
* * * * 
In this example, notice how each line contains exactly n stars and starts with a precise amount of space, reducing by one on each subsequent line.

Example 1:

Input:

n=1

Output:

* 
Explanation:A single row rhombus with one '*' for n=1.

Example 2:

Input:

n=2

Output:

 * * 
* * 
Explanation:A rhombus pattern with two rows.

Example 3:

Input:

n=3

Output:

  * * * 
 * * * 
* * * 
Explanation:A rhombus pattern with three rows.

*/



class Solution {
public:
    void printRhombus(int n) {
        // Implement the pattern printing logic here

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                cout<<" ";
            }
            for(int j=1;j<=n;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};