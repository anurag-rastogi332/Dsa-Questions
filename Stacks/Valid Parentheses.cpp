#include <iostream>
#include <stack>
using namespace std;

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/

class Solution
{
public:
    bool isValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '[' || ch == '{')
            {
                // insert
                st.push(ch);
            }

            else
            {
                // closing bracket
                // match/no match
                // pre check
                if (st.empty())
                {
                    return false;
                }
                else if (ch == ')' && st.top() != '(')
                {
                    // not match
                    return false;
                }
                else if (ch == '}' && st.top() != '{')
                {
                    return false;
                }
                else if (ch == ']' && st.top() != '[')
                {
                    return false;
                }
                else
                {
                    // match
                    st.pop();
                }
            }
        }
        // yaha per main galti krta hu
        // ye bhul jate hai case
        if (st.empty())
        {
            // iska mtlb sare bracket cancel ho gaye
            return true;
        }
        else
        {
            // cancel out ho gaye but still something is left in the stack
            return false;
        }
        // in dono if else case ki jagah hum return st.empty bhi likh sakte hain
    }
};

/*

Short Logic (Valid Parentheses – Stack)

Push every opening bracket (, {, [ into the stack.

For every closing bracket:

If the stack is empty → invalid 

Otherwise, check the top of the stack:

) must match (

} must match {

] must match [

If it matches, pop the stack; otherwise, invalid 

At the end, if the stack is empty, all brackets were matched → valid 

If anything is left in the stack → invalid 


*/