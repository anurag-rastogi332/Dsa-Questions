#include<iostream>
#include<vector>
using namespace std;



/*

You are given a string array events.

Initially, score = 0 and counter = 0. Each element in events is one of the following:

"0", "1", "2", "3", "4", "6": Add that value to the total score.
"W": Increase the counter by 1. No score is added.
"WD": Add 1 to the total score.
"NB": Add 1 to the total score.
Process the array from left to right. Stop processing when either:

All elements in events have been processed, or
The counter becomes 10.
Return an integer array [score, counter], where:

score is the final total score.
counter is the final counter value.
 

Example 1:

Input: events = ["1","4","W","6","WD"]

Output: [12,1]

Explanation:

Event	Score	Counter
"1"	1	0
"4"	5	0
"W"	5	1
"6"	11	1
"WD"	12	1
Final result: [12, 1].

Example 2:

Input: events = ["WD","NB","0","4","4"]

Output: [10,0]

Explanation:

Event	Score	Counter
"WD"	1	0
"NB"	2	0
"0"	2	0
"4"	6	0
"4"	10	0
Final result: [10, 0].

Example 3:

Input: events = ["W","W","W","W","W","W","W","W","W","W","W"]

Output: [0,10]

Explanation:

After 10 occurrences of "W", the counter reaches 10, so processing stops. The remaining events are ignored.

 

Constraints:

1 <= events.length <= 1000
events[i] is one of "0", "1", "2", "3", "4", "6", "W", "WD", or "NB".

*/

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int>ans;
        int count=0;
        int score=0;
        for(auto x:events){
            if(x=="0"){
                score+=0;
            }
        else if(x=="1"){
            score+=1;
        }            
        else if(x=="2"){
            score+=2;
        }
            else if(x=="3"){
                score+=3;
            }
            else if(x=="4"){
                score+=4;
            }
            else if(x=="6"){
             score+=6;
            }
            else if(x=="W"){
                 count+=1;
                if(count==10){
                    break;
                }
             }
            else if(x=="WD"){
                score+=1;
            }
            else{
                score+=1;
            }
        }
        ans.push_back(score);
        ans.push_back(count);
        return ans;
    }
};