/* LC-0020-ValidParentheses

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

*/

#include "..\tools.h"

using namespace std;

/* ------------------------------------------------------------------------- */
static string print(vector<int>& v)
{
    string res = "[";

    for (int n : v)
        res += to_string(n) + ", ";

    return res + "]";
}

/* ------------------------------------------------------------------------- */

static bool isValid(string s)
{
    stack<char> stack;

    for (char c : s)
    {
        if (c == '{' || c == '[' || c == '(')
        {
            stack.push(c);
        }
        else
        {
            if (stack.empty())
                return false;

            char top = stack.top();
            stack.pop();

            if ((c == '}' && top != '{') || (c == ']' && top != '[') || (c == ')' && top != '('))
                return false;
        }
    }

    return stack.empty();
}

/* ------------------------------------------------------------------------- */
void lc_0020()
{

    std::cout << isValid("[{}()]{}{") << "\n";
}


