/* LC-0151-ReverseWordsInAString

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

#include "..\tools.h"
using namespace std;

string reverseWords(string s)
{
    std::string result;

    while (!s.empty())
    {

        while (!s.empty() && s[s.size() - 1] == ' ')
            s.pop_back();

        std::string word;

        while (!s.empty() && s[s.size() - 1] != ' ')
        {
            word.push_back(s[s.size() - 1]);
            s.pop_back();
        }

        if (word.size() > 0 && !result.empty())
            result += " ";

        for (int i = word.size() - 1; i >= 0; i--)
            result += word[i];
    }

    return result;

}

void lc_0151()
{
    std::cout << "" << reverseWords("Hello World") << "\n";
    std::cout << "" << reverseWords("the sky is blue") << "\n";
    std::cout << "" << "'" << reverseWords("  hello world  ") << "'" << "\n";
}

