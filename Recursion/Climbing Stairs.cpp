#include<iostream>
using namespace std;

/*

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

*/

class Solution {
public:
    void solve(int n, int &count){
        if(n<0){
            return;
        }
       if(n==0) {
        count++; 
        return ;
       }
      solve(n-1,count);
      solve(n-2,count); 

    }
    int climbStairs(int n) {
        int count=0;
        solve(n,count);
        return count;
    }
};
