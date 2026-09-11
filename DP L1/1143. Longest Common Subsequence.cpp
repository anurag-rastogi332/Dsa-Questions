#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


*/

class Solution
{
public:
    /*
        int solveUsingRec(int i,int j,string t1,string t2){
            // base case isme mai handle karunga
            if(i>=t1.size() || j>=t2.size()){
                return 0;
            }
              // maine ye socha hai ki agar t1[i]==t2[j] hai to maine i++ aur j++ dono kr dunga

            if(t1[i]==t2[j]){
                return 1+solveUsingRec(i+1,j+1,t1,t2);
            }
             // baki ka mai recursion ko de dunga
            else{
                return max(solveUsingRec(i+1,j,t1,t2),solveUsingRec(i,j+1,t1,t2));
                }
        }
    */

    /*
        int solveUsingDp(int i,int j,string t1,string t2,vector<vector<int>>&dp){
            // base case isme mai handle karunga
            if(i>=t1.size() || j>=t2.size()){
                return 0;
            }
            //if the answer already exist
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            // maine ye socha hai ki agar t1[i]==t2[j] hai to maine i++ aur j++ dono kr dunga
            if(t1[i]==t2[j]){
                int ans1= 1+solveUsingDp(i+1,j+1,t1,t2,dp);
                dp[i][j]=ans1;
               return ans1;
            }
             // baki ka mai recursion ko de dunga
            else{
               int ans2= max(solveUsingDp(i+1,j,t1,t2,dp),solveUsingDp(i,j+1,t1,t2,dp));
               dp[i][j]=ans2;
               return ans2;
                }
        }
       */

    // solve using tabulation method
    int solveUsingTab(string t1, string t2)
    {
        // create a 2d vector , and fill with the base case analysis
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i > n || j > m)
                {
                    continue;
                }
                else
                {
                    if (t1[i] == t2[j])
                    {
                        int ans1 = 1 + dp[i + 1][j + 1];
                        dp[i][j] = ans1;
                    }
                    // baki ka mai recursion ko de dunga
                    else
                    {
                        int ans2 = max(dp[i + 1][j], dp[i][j + 1]);
                        dp[i][j] = ans2;
                    }
                }
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        // int ans=solveUsingRec(i,j,text1,text2);
        //  return ans;
        /*
        //    convert it into dp
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int dpAns=solveUsingDp(i,j,text1,text2,dp);
        return dpAns;
        */

        //  now convert it into the tabulation method
        int tabAns = solveUsingTab(text1, text2);
        return tabAns;
    }
};