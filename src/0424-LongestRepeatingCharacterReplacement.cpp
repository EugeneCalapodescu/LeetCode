/*

	LC 424 - Longest Repeating Character Replacement

	You are given a string s and an integer k. You can choose any character of the string and change it
	to any other uppercase English character. You can perform this operation at most k times.

	Return the length of the longest substring containing the same letter you can get after performing the above operations.

	Example 1:
		Input: s = "ABAB", k = 2
		Output: 4
		Explanation: Replace the two 'A's with two 'B's or vice versa.

	Example 2:
		Input: s = "AABABBA", k = 1
		Output: 4
		Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
		The substring "BBBB" has the longest repeating letters, which is 4.


*/

#include "..\tools.h"

using namespace std;

int replacements(const std::string& s, int start, int end)
{
	char map[26] = {};
	char max = 0;

	for (int i = start; i <= end; i++)
	{
		map[s[i] - 'A']++;
		max = std::max(max, map[s[i] - 'A']);
	}

	// printf("%s: %d\n", s.substr(start, end - start + 1).c_str(), end - start + 1 - max);

	return end - start + 1 - max;
}

int characterReplacement_v1(string s, int k)
{
	int max = 0;
	int N = (int)s.size();

	for (int start = 0, end = 0; start < N; start++)
	{
		while (end < N)
		{
			int r = replacements(s, start, end);
			if (r <= k)
				end++;
			else
				break;
		}

		max = std::max(max, end - start);
	}

	return max;
}

int characterReplacement(std::string s, int k) 
{
	if (s.empty()) 
		return 0;

	int freqs[26] = { 0 };
	int start = 0;
	int max_freq = 0;
	int max_len = 0;

	for (int end = 0; end < s.size(); ++end) 
	{
		freqs[s[end] - 'A']++;
		max_freq = std::max(max_freq, freqs[s[end] - 'A']);

		while ((end - start + 1) - max_freq > k) 
		{
			freqs[s[start] - 'A']--;
			start++;
		}

		max_len = std::max(max_len, end - start + 1);
	}

	return max_len;
}

void lc_0424()
{
	printf("%d\n", characterReplacement("ABAB", 2)); // 4
	printf("%d\n", characterReplacement("AABABBA", 1)); // 4
	printf("%d\n", characterReplacement("ABBB", 2)); // 4

}