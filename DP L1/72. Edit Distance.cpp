#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:


    int solveUsingRecurtion(string &a, string &b,int i, int j){
          //base cases 
          if(i==a.length()){
           return b.length()-j;
          }
          if(j==b.length()){
         return a.length()-i;
          }
          int ans=0;
          if(a[i]==b[j]){
            ans= solveUsingRecurtion(a,b,i+1,j+1);
          }
          else{
            // operations perform krne hai
            int insert=1+solveUsingRecurtion(a,b,i,j+1);
            int deleted=1+solveUsingRecurtion(a,b,i+1,j);
            int replace =1+solveUsingRecurtion(a,b,i+1,j+1);
            ans=min(insert, min(deleted,replace));
          }
          return ans;
    }
   

   
    int solveMem(string &a, string &b,int i, int j,vector<vector<int>>&dp){
          //base cases 
          if(i==a.length()){
           return b.length()-j;
          }
          if(j==b.length()){
         return a.length()-i;
          }
          if(dp[i][j]!=-1){
            return dp[i][j];
          }
          int ans=0;
          if(a[i]==b[j]){
            ans= solveMem(a,b,i+1,j+1,dp);
          }
          else{
            // operations perform krne hai
            int insert=1+solveMem(a,b,i,j+1,dp);
            int deleted=1+solveMem(a,b,i+1,j,dp);
            int replace =1+solveMem(a,b,i+1,j+1,dp);
            ans=min(insert, min(deleted,replace));
          }
          dp[i][j]=ans;
         return dp[i][j];

    }


     int solveTab(string &a, string &b) {
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,-1));
        for(int j=0;j<=b.length();j++){
            dp[a.length()][j]=b.length()-j;
        }
        for(int i=0;i<=a.length();i++){
            dp[i][b.length()]=a.length()-i;
        }
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
           int ans=0;
          if(a[i]==b[j]){
            ans= dp[i+1][j+1];
          }
          else{
            // operations perform krne hai
            int insert=1+dp[i][j+1];
            int deleted=1+dp[i+1][j];
            int replace =1+dp[i+1][j+1];
            ans=min(insert, min(deleted,replace));
          }
          dp[i][j]=ans;
        
            }
        }
         return dp[0][0];
     }

    int minDistance(string word1, string word2) {
        if(word1.length()==0){
            return word2.length();
        }
        if(word2.length()==0){
            return word1.length();
        }
        int i=0;
        int j=0;
        // return solveUsingRecurtion(word1,word2,i,j);

        //convert this code into the memorization 
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // int dpAns=solveMem(word1,word2,i,j,dp);
        // return dpAns;
        // solve using tabulation method 
        int tabAns=solveTab(word1,word2);
        return tabAns;
    }
};