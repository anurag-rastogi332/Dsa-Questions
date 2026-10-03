#include <iostream>
#include <vector>
using namespace std;

/*

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.



Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


*/

class Solution
{
public:
    /*
     bool solve(string s1,string s2,string s3,int i,int j,int k){
         // base case
         if(i==s1.size() && j==s2.size() && k==s3.size()){
              return true;
         }

         // 1 case solve
         bool ans1=false;
         if(s3[k]==s1[i]){
             ans1=solve(s1,s2,s3,i+1,j,k+1);
         }
         bool ans2=false;
         if(s3[k]==s2[j]){
              ans2=solve(s1,s2,s3,i,j+1,k+1);
         }

         return ans1 || ans2;

     }
    */

    /*
         bool solveDp(string s1,string s2,string s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
            // base case
            if(i==s1.size() && j==s2.size() && k==s3.size()){
                 return true;
            }
            if(dp[i][j][k]!=-1){
                return dp[i][j][k];
            }
            // 1 case solve
            bool ans1=false;
            if(s3[k]==s1[i]){
                ans1=solveDp(s1,s2,s3,i+1,j,k+1,dp);
            }
            bool ans2=false;
            if(s3[k]==s2[j]){
                 ans2=solveDp(s1,s2,s3,i,j+1,k+1,dp);
            }

           bool ans= ans1 || ans2;
           return  dp[i][j][k]=ans;
        }
    */

    bool solveTab(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();

        dp[n][m][l] = 1;

        for (int i = n; i >= 0; i--)
        {
            for (int j = m; j >= 0; j--)
            {
                for (int k = l; k >= 0; k--)
                {
                    if (i == n && j == m && k == l)
                        continue;
                    bool ans1 = false;
                    if (i < n &&
                        k < l && s3[k] == s1[i])
                    {
                        ans1 = dp[i + 1][j][k + 1];
                    }
                    bool ans2 = false;
                    if (j < m &&
                        k < l && s3[k] == s2[j])
                    {
                        ans2 = dp[i][j + 1][k + 1];
                    }

                    dp[i][j][k] = ans1 || ans2;
                }
            }
        }
        return dp[0][0][0];
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        int i = 0;
        int j = 0;
        int k = 0;
        //  bool ans=solve(s1,s2,s3,i,j,k);
        //   return ans;
        // convert it into the Mem dp
        /*      vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1, -1)));
                bool ans=solveDp(s1,s2,s3,i,j,k,dp);
                return ans;
        */

        // tabulation approach
        vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, -1)));
        bool ansTb = solveTab(s1, s2, s3, i, j, k, dp);
        return ansTb;
    }
};