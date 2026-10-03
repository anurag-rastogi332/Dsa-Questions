#include<iostream>
#include<vector>
using namespace std;




class Solution {
public:

    bool solve(string &s,string &p,int i,int j){
        //base cases 
        if(i==s.size() && j==p.size()) return true; 
        // j is finished but the i is not finished 
        if (j == p.size()) {
            return false;
        }
        if (i == s.size()) {
           
            while (j < p.size()) {
                if (p[j] != '*') {
                    return false;
                }
                j++;
            }
            return true;
        }

        if(p[j]=='*'){
            bool inc=solve(s,p,i+1,j);
            bool exc=solve(s,p,i,j+1);
            return inc||exc;
        }       
        // and recursive calls 
        bool ans2=false;
        bool ans3=false;
        if(p[j]=='?'){
           ans2=solve(s,p,i+1,j+1);
        }    
        if(p[j]==s[i]) 
        ans3= solve(s,p,i+1,j+1);
        return ans2||ans3;   
         } 
      

    bool Memsolve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
          //base cases 
        if(i==s.size() && j==p.size()) return true; 
        // j is finished but the i is not finished 
        if (j == p.size()) {
            return false;
        }
        if (i == s.size()) {
           
            while (j < p.size()) {
                if (p[j] != '*') {
                    return false;
                }
                j++;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]=='*'){
            bool inc=Memsolve(s,p,i+1,j,dp);
            bool exc=Memsolve(s,p,i,j+1,dp);
            return dp[i][j]= inc||exc;
        }       
        // and recursive calls 
        bool ans2=false;
        bool ans3=false;
        if(p[j]=='?'){
           ans2=Memsolve(s,p,i+1,j+1,dp);
        }    
        if(p[j]==s[i]) 
        ans3= Memsolve(s,p,i+1,j+1,dp);
        return dp[i][j]=ans2||ans3;  
    }    

    bool isMatch(string s, string p) {
       //if the both strings are empty then return true
        if(s.size()==0 && p.size()==0){
            return true;
        }
        int i=0;
        int j=0;
        // bool ans= solve(s,p,i,j);
        // return ans;
        
        //Mem
       vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
       bool MemAns=Memsolve(s,p,i,j,dp);
       return MemAns;
    }
};