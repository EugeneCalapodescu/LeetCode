/*

	LC 205 Isomorphic Strings

	Given two strings s and t, determine if they are isomorphic.
	Two strings sand t are isomorphic if the characters in s can be replaced to get t.

	All occurrences of a character must be replaced with another character while preserving the order of characters.
	No two characters may map to the same character, but a character may map to itself.

	Examples:
		Input: s = "egg", t = "add"
		Output : true

		Input: s = "foo", t = "bar"
		Output: false

		Input: s = "paper", t = "title"
		Output: true

	Can do better with just an array[256] instead of a map
*/

#include "..\tools.h"

using namespace std;

bool isIsomorphic(string s, string t)
{
	if (s.size() != t.size())
		return false;

	std::map<char, char> tr1;
	std::map<char, char> tr2;

	for (int i = 0; i < s.size(); i++)
	{
		auto it1 = tr1.find(s[i]);
		if (it1 != tr1.end() && it1->second != t[i])
			return false;

		tr1[s[i]] = t[i];

		auto it2 = tr2.find(t[i]);
		if (it2 != tr2.end() && it2->second != s[i])
			return false;

		tr2[t[i]] = s[i];
	}


	return true;
}

void lc_0205()
{
	string s1 = "foo";
	string s2 = "bar";

	printf("%d\n", isIsomorphic(s1, s2));

	s1 = "paper";
	s2 = "title";

	printf("%d\n", isIsomorphic(s1, s2));

	s1 = "add";
	s2 = "egg";

	printf("%d\n", isIsomorphic(s1, s2));

	s1 = "badc";
	s2 = "baba";

	printf("%d\n", isIsomorphic(s1, s2));
}