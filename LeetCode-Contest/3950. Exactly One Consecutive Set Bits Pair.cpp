#include<iostream>
#include<algorithm>
using namespace std;

/*

You are given an integer n.

Return true if its binary representation contains exactly one pair of consecutive set bits, and false otherwise.

 

Example 1:

Input: nums = 6

Output: true

Explanation:

Binary representation of 6 is 110.
There is exactly one pair of consecutive set bits ("11"). Thus, the answer is true​​​​​​​.
Example 2:

Input: nums = 5

Output: false

Explanation:

Binary representation of 5 is 101.
There are no consecutive set bits. Thus, the answer is false​​​​​​​.
 

Constraints:

0 <= n <= 105


*/


class Solution {
public:
    bool consecutiveSetBits(int n) {
        string binary="";
        int count=0;
        while(n>0){
            binary+=(n%2)+'0';
            n=n/2;
        }
       reverse(binary.begin(),binary.end());
        for(int i=1;i<binary.size();i++){
            if(binary[i-1]=='1' && binary[i]=='1'){
             count++;
            }
        }

        return count==1;
    }
};