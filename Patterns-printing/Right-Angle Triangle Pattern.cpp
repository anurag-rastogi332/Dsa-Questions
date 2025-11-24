

#include<iostream>
using namespace std;
/*

Example:
If the input n = 4, the expected output is:


*  
* *  
* * *  
* * * *  
Each line of output should correspond to a row of the triangle, following the pattern described above.

Example 1:

Input:

n=2

Output:

* 
* * 
Explanation:A right-angle triangle pattern of height 2.

Example 2:

Input:

n=3

Output:

* 
* * 
* * * 
Explanation:A right-angle triangle pattern of height 3.

Example 3:

Input:

n=5

Output:

* 
* * 
* * * 
* * * * 
* * * * * 
Explanation:A right-angle triangle pattern of height 5.

*/


class Solution {
public:
    void printRightAngleTriangle(int n) {
        // Implement the pattern printing logic here
        for(int i=1; i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<"* ";
            }
            cout<<endl;
        }
    }
};