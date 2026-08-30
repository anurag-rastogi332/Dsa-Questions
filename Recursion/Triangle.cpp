#include<iostream>
#include<vector>
using namespace std;

/*

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

*/


class Solution {
public:
    int solve(vector<vector<int>>&triangle,int row,int col ){
        if(row==triangle.size()-1){
            return triangle[row][col];
        }
        int down=triangle[row][col] +solve(triangle,row+1,col);
        int plus=triangle[row][col] +solve(triangle,row+1,col+1);
        return min(down,plus);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle,0,0);
    }
};
