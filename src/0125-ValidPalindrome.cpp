/* LC-0125-ValidPalindrome


A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and
removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
Explanation:
    "amanaplanacanalpanama" is a palindrome.

*/

#include "..\tools.h"

using namespace std;


bool isPalindrome(string s)
{
    s.erase(remove_if(s.begin(), s.end(),
        [](unsigned char c) { return !isalnum(c); }), s.end());

    if (s.size() < 2)
        return true;

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // we could also do the loop and eliminate the non alpha characters inside the loop
    // that would be optimal, but it's good to practice the stl transformations

    size_t p1 = 0;
    size_t p2 = s.size() - 1;

    while (p1 < p2)
    {
        if (s[p1++] != s[p2--])
            return false;
    }

    return true;
}


/* ------------------------------------------------------------------------- */
void lc_0125()
{
    string s = "A man, a Plan, a Canal: Panama!";

    std::cout << s << " " << isPalindrome(s) << "\n";

    s = "Was it a car or a cat I saw?";
    std::cout << s << " " << isPalindrome(s) << "\n";
}

