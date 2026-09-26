#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*   
      int solveUsingRec(vector<int>& days, vector<int>& costs,int i){
        //base condition
        if(i>=days.size()) return 0;
        // sol for the one case
        //1 days pass taken
        int cost1=costs[0]+solveUsingRec(days,costs,i+1);
        //7 days pass taken
        int passEndDay=days[i]+7-1;
        int j=i;
        while( j < days.size() &&days[j]<=passEndDay){
            j++;
        }
        int cost7=costs[1]+solveUsingRec(days,costs,j);

         //30 days pass taken
         passEndDay=days[i]+30-1;
         j=i;
        while( j < days.size() &&days[j]<=passEndDay){
            j++;
        }
        int cost30=costs[2]+solveUsingRec(days,costs,j);
        return min(cost1,min(cost7,cost30));
    } 
    */
    
      int solveDp(vector<int>& days, vector<int>& costs,int i,vector<int>&dp){
        //base condition
        if(i>=days.size()) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        // sol for the one case
        //1 days pass taken
        int cost1=costs[0]+solveDp(days,costs,i+1,dp);
        //7 days pass taken
        int passEndDay=days[i]+7-1;
        int j=i;
        while( j < days.size() && days[j]<=passEndDay){
            j++;
        }
        int cost7=costs[1]+solveDp(days,costs,j,dp);
         //30 days pass taken
         passEndDay=days[i]+30-1;
         j=i;
        while( j < days.size() &&days[j]<=passEndDay){
            j++;
        }
        int cost30=costs[2]+solveDp(days,costs,j,dp);
        return dp[i]=min(cost1,min(cost7,cost30));
    } 

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solveUsingRec(days,costs,0);
          vector<int>dp(days.size(),-1);
          int dpAns=solveDp(days,costs,0,dp);
          return dpAns;
    }
};