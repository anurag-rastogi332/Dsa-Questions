#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
  
     /*
     int solveUsingRec(int cap,vector<int>&val,vector<int>&wt,int index){
         //base case
         if(index>= val.size()){
              return 0;
         }
         
         //incldue/exclude
         int includeAns=0;
         if(wt[index]<=cap){
             includeAns=val[index]+solveUsingRec(cap-wt[index],val,wt,index+1);
         }
         int excludeAns=0+solveUsingRec(cap,val,wt,index+1);
         int ans=max(includeAns,excludeAns);
         return ans;
         
     }
     */
     
     /*
     // solveUsingMem
     int solveUsingMem(int cap,vector<int>&val,vector<int>&wt,int index,vector<vector<int>>&dp){
          //base case
         if(index>= val.size()){
              return 0;
         }
         if(dp[cap][index]!=-1){
             return dp[cap][index];
         }
         //incldue/exclude
         int includeAns=0;
         if(wt[index]<=cap){
             includeAns=val[index]+solveUsingMem(cap-wt[index],val,wt,index+1,dp);
         }
         int excludeAns=0+solveUsingMem(cap,val,wt,index+1,dp);
         int ans=max(includeAns,excludeAns);
         dp[cap][index]=ans;
         return ans;
     }
     */
     
          int solveUsingTabulation(int cap,vector<int>&val,vector<int>&wt){
               int n=wt.size();
              vector<vector<int>>dp(cap+1,vector<int>(n+1,0));
              //base case analyase krne ke baad we got that for index=n, we need to set o as answer
              for(int i=0;i<=cap;i++){
                  for(int j=n-1;j>=0;j--){
                        int includeAns=0;
         if(wt[j]<=i){
             includeAns=val[j]+dp[i-wt[j]][j+1];
         }
         int excludeAns=0+dp[i][j+1];
         int ans=max(includeAns,excludeAns);
         dp[i][j]=ans;
                  }
              }
              return dp[cap][0];
          }
       
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       /* int  index=0;
        int ans=solveUsingRec(W,val,wt,index);
        return ans;
        */
        
        /*
        // solveUsingMem
        int index=0;
        int n=wt.size();
        vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        int memAns= solveUsingMem(W,val,wt,index,dp);
        return memAns;
        */
        
        //solveUsingTabulation
        //two paramerters :-capacity,index
        int index=0;
        int tabAns=solveUsingTabulation(W,val,wt);
        return tabAns;
        
        
        
    }
}; 