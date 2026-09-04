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
/*
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
*/

    int solveUsingMem(vector<int>&arr,int curr,int prev,vector<vector<int>>&dp){
         //base case
        if(curr>=arr.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        // 1 case main solve karunga
        int includeAns=0; 
        if(prev==-1 || arr[curr]>arr[prev]){
            includeAns=1+solveUsingMem(arr,curr+1,curr,dp);
        } 
        int excludeAns=0+solveUsingMem(arr,curr+1,prev,dp);
        int finalAns=max(includeAns,excludeAns);
        dp[curr][prev+1]=finalAns;
        return finalAns;
    } 
     
     // bottom up approach /tabulation approach 
     int solveUsingTabulation(vector<int>&nums){
        //step: dp array 
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //step2:-analyse base case and fill the dp array 
        //i found out that for curr=n,all answers should be 0 in dp array 
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                 int includeAns=0; 
        if(prev==-1 || nums[curr]>nums[prev]){
            includeAns=1+dp[curr+1][curr+1];
        } 
        int excludeAns=0+dp[curr+1][prev+1];
        int finalAns=max(includeAns,excludeAns);
        dp[curr][prev+1]=finalAns;
            }
        }
        return dp[0][0];
     }


    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;
        //curr and prev are denoting indexes
        // int ans=solveUsingRec(nums,curr,prev);
        //2d dp 
        //create , initialise, send, receive dp array
        // dp array ->parameters curr,prev
       /* int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=solveUsingMem(nums,curr,prev,dp);
        return ans;*/
        int ans=solveUsingTabulation(nums);
        return ans;
    }
};
