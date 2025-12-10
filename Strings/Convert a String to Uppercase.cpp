#include<iostream>
using namespace std;


/*

Example 1:

Input:

Input: "hello world"

Output:

HELLO WORLD
Explanation:All lowercase letters are converted to uppercase.

Example 2:

Input:

Input: "TeStInG"

Output:

TESTING
Explanation:Mixed uppercase and lowercase letters are converted to all uppercase.

Example 3:

Input:

Input: "c++ programming"

Output:

C++ PROGRAMMING
Explanation:Letters are converted to uppercase, but special characters remain unchanged.

*/

class Solution {
public:
    string toUpperCase(string s) {
      
      for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            s[i]=s[i]-'a'+'A';
        }
      }
      return s;
    }
};