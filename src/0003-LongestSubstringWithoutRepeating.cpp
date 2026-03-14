/*
	Given a string s, find the length of the longest substring without duplicate characters.
	A substring is a contiguous sequence of characters within a string.

*/

#include "..\tools.h"

/*
	A nicer way to write it: firts remove duplicates then do the insert
*/

int lengthOfLongestSubstring(std::string s)
{
	int N = s.size();
	int max = 0;
	int left = 0, right = 0;

	std::unordered_set<char> set;
	while (left < N && right < N)
	{
		while (set.contains(s[right]))
			set.erase(s[left++]);
			
		set.insert(s[right++]);
		max = std::max(max, right - left);
	}

	return max;

}

/*
Sliding window
	left and right pointers with the current window
	if the current char is a duplicate, then we need to move the left pointer
*/

int lengthOfLongestSubstring_v1(std::string s) 
{
	int N = s.size();
	int max = 0;
	int left = 0, right = 0;

	std::unordered_set<char> set;
	while(left < N && right < N)
	{
		if (! set.contains(s[right]))
		{
			set.insert(s[right++]);
			max = std::max(max, right - left);
		}
		else
		{
			while (left < right)
			{
				set.erase(s[left]);
				left++;
				if (s[left - 1] == s[right])
					break;
			}
		}
	}

	return max;

}

void lc_0003()
{
	std::cout << lengthOfLongestSubstring("abcbada") << "\n";
}