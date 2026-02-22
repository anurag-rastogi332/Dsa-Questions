#include <iostream>
#include <stack>

using namespace std;

/*


Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.
Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

Examples:

Input: s = "((a+b))"
Output: true
Explanation: ((a+b)) can reduced to (a+b).
Input: s = "(a+(b)/c)"
Output: true
Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.
Input: s = "(a+b+(c+d))"
Output: false
Explanation:(a+b+(c+d)) doesn't have any redundant or multiple brackets.
*/

class Solution
{
public:
    bool checkRedundancy(string &s)
    {

        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                st.push(ch);
            }

            else if (ch == ')')
            {

                bool operatorFound = false;

                while (!st.empty() && st.top() != '(')
                {

                    char value = st.top();
                    if (value == '+' || value == '-' || value == '*' || value == '/')
                    {
                        operatorFound = true;
                    }
                    st.pop();
                }

                if (operatorFound == false)
                {
                    return true;
                }
                else
                {
                    // brackets non-redundant
                    // opening bracket ko remove krna hai
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
            }
        }
        // agar yaha tak aa gye -> iska mtlb
        // no redundant bracket
        return false;
    }
};

/*

🧠 Algorithm Story: “Bracket ke Andar Kya Hai?”

Socho tumhare paas ek expression hai:
((a+b)) ya (a) ya (a+b*c)

Tumhara kaam hai ye pata lagana:
👉 kya koi bracket pair bina kaam ke hai?
Yaani bracket ke andar *koi operator (+, -, , /) hai ya nahi.

🎒 Stack = Ek Bag

Hum ek bag (stack) lete hain jisme hum:

Opening bracket '(' daalte hain

Operators + - * / daalte hain

Operands (a, b, c, 1, 2) ko ignore kar dete hain, kyunki redundancy decide karne me unka role nahi.

🚶 Expression ko Left se Right Padho

Hum string ko ek-ek character karke dekhte hain:

🔹 Case 1: '(' ya Operator mila

👉 Bag (stack) me daal do.
Matlab: “ye important cheez hai, baad me kaam aayegi”.

🔹 Case 2: ')' mila

Ab bracket close ho raha hai, matlab:
👉 “Ab check karo ki is bracket ke andar kuch meaningful tha ya nahi”.

Stack se elements nikaalte jao jab tak '(' na mil jaye

Agar beech me koi operator mila
👉 Matlab bracket ka use tha (non-redundant)

Agar koi operator nahi mila
👉 Matlab bracket bekaar tha ❌
👉 Turant true return (redundant found)

Phir opening bracket '(' ko bhi hata dete hain (kyunki wo pair complete ho gaya).

✅ End Tak Pahunch Gaye?

Agar poora expression check ho gaya aur kahin bhi “bekaar bracket” nahi mila,
toh matlab:

👉 No redundant brackets
Return false.

🎯 Real-Life Example

Expression:

(a)


Story:

( bag me gaya

a ignore

) aaya

Bag ke andar sirf ( tha, koi operator nahi ❌
➡️ Bracket bekaar hai → redundant

Expression:

(a+b)


Story:

( gaya

+ gaya

) aaya

Bag ke andar + mila ✅
➡️ Bracket ka kaam hai → non-redundant


*/