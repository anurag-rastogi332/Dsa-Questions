#include<iostream>
using namespace std;


/*

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

*/

class Solution {
public:
     bool solve(string s,string t,int i,int j){
        // base case   
        if(i==s.size()){
            return true;
        }
        if(j==t.size()){
            return false;
        }   
        // 1 case jo main handle karunga
        if(s[i]!=t[j]){
           return solve(s,t,i,j+1);
        }
           
        // recursive call karunga yaha per mai 
      return  solve(s,t,i+1,j+1);
 
     }
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        bool ans=solve(s,t,i,j);
        return ans;
    }
};
