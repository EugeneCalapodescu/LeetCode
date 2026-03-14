/* LC-0022-GenerateParentheses



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
static void generate(string s, int n, int open, int close, vector<string>& result)
{
    if (close == n)
        result.push_back(s);

    if (open < n)
        generate(s + "(", n, open + 1, close, result);

    if (close < n && close < open)
        generate(s + ")", n, open, close + 1, result);
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generate("", n, 0, 0, result);

    return result;
}


/* ------------------------------------------------------------------------- */
void lc_0022()
{
    vector<string> v = generateParenthesis(4);

    std::cout << "\n";
}

