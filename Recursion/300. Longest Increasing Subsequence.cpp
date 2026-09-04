#include<iostream>
#include<vector>
using namespace std;

/*

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/

class Solution {
public:
    int solveUsingRec(vector<int>&arr,int curr,int prev){
        //base case
        if(curr>=arr.size()){
            return 0;
        }
        // 1 case main solve karunga
        int includeAns=0; 
        if(prev==-1 || arr[curr]>arr[prev]){
            includeAns=1+solveUsingRec(arr,curr+1,curr);
        } 
        int excludeAns=0+solveUsingRec(arr,curr+1,prev);
        int finalAns=max(includeAns,excludeAns);
        // baki ka recursion ko de dunga
        return finalAns;

    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        //curr and prev are denoting indexes
        int ans=solveUsingRec(nums,curr,prev);
        return ans;
    }
};
