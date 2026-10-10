#include "..\tools.h"

using namespace std;

/*
	You are given an array nums with n objects colored red, white, or blue, 
	sort them in - place so that objects of the same color are adjacent, 
	with the colors in the order red, white, and blue.

	We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

	You must solve this problem without using the library's sort function.
*/

void sortColors(vector<int>& nums)
{
	int freq[3] {};

	for (size_t i = 0; i < nums.size(); i++)
		freq[nums[i]]++;

	int end = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < freq[i]; j++)
			nums[end++] = i;
}

void lc_0075()
{
	vector<int> v{ 1, 2, 0, 2, 1, 0 };
	sortColors(v);

	cout << to_string(v);
}