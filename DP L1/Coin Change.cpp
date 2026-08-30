#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

*/

class Solution
{
public:
    /*
         int solveUsingRecursion(vector<int>&coins,int amount){
            //base case
            if(amount==0){
                return 0;
            }

            //isse amount ko create krne ke liye
            // i will try each and every coin
            int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(coins[i]<=amount){
                    //valid case
                    // maine ek coin use kr liya
                    int recursionAns=solveUsingRecursion(coins,amount-coins[i]);
                    // recursion ka answer can be valid or invalid
                    if(recursionAns!=INT_MAX){
                        //ek valid answer mila hai
                        // it may or may not be a minimum number
                        mini=min(mini,1+recursionAns);
                    }

                }
            }
            return mini;
         }
       */

    /*
         recu+mem
         1d dp
         int  solveUsingDp(vector<int>&coins,int amount,vector<int>&dp){
            //base case
            if(amount==0){
                return 0;
            }
            if(dp[amount]!=-1){
                return dp[amount];
            }
              //isse amount ko create krne ke liye
            // i will try each and every coin
            int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(coins[i]<=amount){
                    //valid case
                    // maine ek coin use kr liya
                    int recursionAns=solveUsingDp(coins,amount-coins[i],dp);
                    // recursion ka answer can be valid or invalid
                    if(recursionAns!=INT_MAX){
                        //ek valid answer mila hai
                        // it may or may not be a minimum number
                        mini=min(mini,1+recursionAns);
                    }

                }
            }
            dp[amount]=mini;
            return mini;
         }
    */

    // tabulation method
    int solutionUsingTab(vector<int> &coins, int amount)
    {
        // step1:dp array
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);
        // step: analyse base case and fill dp array
        dp[0] = 0;
        // step3: for loop, reverse the flow ,copy paste,looping variable, replace function calls
        //  n represents amount here
        for (int value = 1; value <= amount; value++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++)
            {
                if (coins[i] <= value)
                {
                    // valid case
                    //  maine ek coin use kr liya
                    int recursionAns = dp[value - coins[i]];
                    // recursion ka answer can be valid or invalid
                    if (recursionAns != INT_MAX)
                    {
                        // ek valid answer mila hai
                        //  it may or may not be a minimum number
                        mini = min(mini, 1 + recursionAns);
                    }
                }
            }
            dp[value] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = amount;
        //  int ans=solveUsingRecursion(coins,amount);
        //   if(ans==INT_MAX){
        //     return -1;
        //   }
        //   else{
        //     return ans;
        //   }
        // vector<int>dp(n+1,-1);
        int ans = solutionUsingTab(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};