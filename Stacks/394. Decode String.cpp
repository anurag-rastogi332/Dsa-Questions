#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/*

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

*/


class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch : s){
            if(ch == ']'){
                string temp = "";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    temp += top == "[" ? "" : top;
                    st.pop();
                }

                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(), numericTimes.end());

                int n = stoi(numericTimes);
                string currentDecode = "";
                while(n--){
                    currentDecode += temp;
                }
                st.push(currentDecode);
            }
            else{
                string temp(1, ch);
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};