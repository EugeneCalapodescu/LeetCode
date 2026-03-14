/*

	LC-409 Longest Palindrome

	Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
	Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

	Example 1:
		Input: s = "abccccdd"
		Output: 7
		Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

	Example 2:
		Input: s = "a"
		Output: 1
		Explanation: The longest palindrome that can be built is "a", whose length is 1.

*/

#include "..\tools.h"

using namespace std;

int longestPalindrome(string s)
{
	map<char, int> map;

	if (s.size() < 2)
		return (int)s.size();

	for (int i = 0; i < s.size(); i++)
	{
		auto it = map.find(s[i]);
		if (it == map.end())
			map[s[i]] = 1;
		else
			map[s[i]]++;
	}

	int nb_doubles = 0;
	int nb_singles = 0;
	for (auto kv : map)
	{
		nb_doubles += kv.second / 2;
		nb_singles += kv.second % 2;
	}

	if (nb_doubles && nb_singles)
		return 2 * nb_doubles + 1;

	if (nb_singles > 0)
		return 1;

	return 2 * nb_doubles;
}

void lc_0409()
{
	std::cout << longestPalindrome("bb") << "\n";
	std::cout << longestPalindrome("a") << "\n";
	std::cout << longestPalindrome("ab") << "\n";
	std::cout << longestPalindrome("aba") << "\n";
	std::cout << longestPalindrome("dccaccd") << "\n";

}