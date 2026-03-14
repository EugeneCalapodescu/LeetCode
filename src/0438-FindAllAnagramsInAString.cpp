/*

	LC 438. Find All Anagrams in a String

	Given two strings s and p, return an array of all the start indices of p's anagrams in s.
	You may return the answer in any order.

	An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
	typically using all the original letters exactly once.

	Example 1:
		Input: s = "cbaebabacd", p = "abc"
		Output: [0,6]
		Explanation:
			The substring with start index = 0 is "cba", which is an anagram of "abc".
			The substring with start index = 6 is "bac", which is an anagram of "abc".

	Example 2:
		Input: s = "abab", p = "ab"
		Output: [0,1,2]
		Explanation:
			The substring with start index = 0 is "ab", which is an anagram of "ab".
			The substring with start index = 1 is "ba", which is an anagram of "ab".
			The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

#include "..\tools.h"
using namespace std;

bool eq(const vector<int>& s, const vector<int>& p)
{
	for (int i = 0; i < p.size(); i++)
		if (s[i] != p[i])
			return false;

	return true;
}

vector<int> findAnagrams(string s, string p)
{
	std::vector<int> p_freq(26);
	std::vector<int> s_freq(26);

	std::vector<int> res;

	for (int i = 0; i < p.size(); i++)
	{
		p_freq[p[i] - 'a']++;
		s_freq[s[i] - 'a']++;
	}

	if (eq(p_freq, s_freq))
		res.push_back(0);

	for (int i = 1; i < s.size() - p.size() + 1; i++)
	{
		s_freq[s[i - 1] - 'a']--;
		s_freq[s[i + p.size() - 1] - 'a']++;

		if (eq(p_freq, s_freq))
			res.push_back(i);
	}

	return res;
}

void lc_0438()
{
	string s = "cbaebabacd";
	string p = "abc";

	auto v = findAnagrams(s, p);

	s = "abab";
	p = "ab";

	v = findAnagrams(s, p);
}
