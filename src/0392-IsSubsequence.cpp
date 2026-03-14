/*

	LC 392 Is Subsequence

	Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

	A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
	of the characters without disturbing the relative positions of the remaining characters.
	(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

	Example 1:
		Input: s = "abc", t = "ahbgdc"
		Output: true

	Example 2:
		Input: s = "axc", t = "ahbgdc"
		Output: false

	isSubsequence_v3 is nicer, it loops on t instead of s
*/

#include "..\tools.h"

using namespace std;

bool isSubsequence_v1(string s, string t)
{
	int is = 0;
	int it = 0;

	for (; is < s.size(); is++)
	{
		if (it == t.size())
			return false;

		while (s[is] != t[it++])
			if (it == t.size())
				return false;
	}

	return true;

}


bool isSubsequence(string s, string t)
{
	const char* p1 = s.c_str();
	const char* p2 = t.c_str();

	while (*p1)
	{
		if (*p2 == 0)
			return false;

		while (*p2 && *p2 != *p1)
			p2++;

		if (*p2 == 0)
			return false;
		else
			p2++;

		p1++;
	}

	return true;

}


bool isSubsequence_v3(string s, string t) {
	auto m = s.size();
	auto n = t.size();
	int j = 0;

	for (auto i = 0; i < n; i++) {
		if (s[j] == t[i])
			j++;
	}

	return j == m;
}


void lc_0392()
{
	printf("%d\n", isSubsequence("abc", "ahbgdc"));
	printf("%d\n", isSubsequence("axc", "ahbgdc"));
	printf("%d\n", isSubsequence("acb", "ahbgdc"));
	printf("%d\n", isSubsequence("acb", ""));
}



