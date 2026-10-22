#include "..\tools.h"

/*
Given a string s, return the longest substring of s that is a palindrome.

A palindrome is a string that reads the same forward and backward.

If there are multiple palindromic substrings that have the same length, 
return any one of them.

Example 1:
	Input: s = "ababd"
	Output: "bab"

Idea: for i = 1 to N, checkl the largest palindrome centered on i (if odd)
      or (i, i+1) if even

lambda eventually to save some typing
*/

using namespace std;

static string longestPalindrome(string s)
{
	if (s.size() == 1)
		return s;

	int start = 0;
	int len = 0;

	auto f = [&](int l, int r) {
		while (l >= 0 && r < s.size() && s[l] == s[r])
		{
			if (r - l + 1 > len)
			{
				start = l;
				len = r - l + 1;
			}

			l--;
			r++;
		}
	};

	for (int i = 0; i < s.size(); i++)
	{
		f(i, i);
		f(i, i + 1);
	}

	return s.substr(start, len);
}


void lc_0005()
{
	std::cout << longestPalindrome("a") << "\n";
	std::cout << longestPalindrome("ab") << "\n";
	std::cout << longestPalindrome("aa") << "\n";
	std::cout << longestPalindrome("aba") << "\n";
}
