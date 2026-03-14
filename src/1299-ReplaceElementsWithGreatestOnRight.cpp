/*
Given an array arr, replace every element in that array with
the greatest element among the elements to its right,
and replace the last element with -1.

After doing so, return the array.

Solution:
	Walk backward, at each step, the biggest is either the previous number in the original array,
	or the previous biggest that we have in the new array
*/

#include "..\tools.h"

std::vector<int> replaceElements(std::vector<int>& arr)
{
	std::vector<int> res(arr);

	if (arr.size() < 1)
		return arr;

	res[arr.size() - 1] = -1;

	for (int i = res.size() - 3; i >= 0; i--)
		res[i] = std::max(arr[i + 1], res[i + 1]);

	return res;
}

void lc_1299()
{
	std::vector<int> v{ 17,18,5,4,6,1 };
	auto v2 = replaceElements(v);
}