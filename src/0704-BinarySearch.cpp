/*

	LC 704 Binary Search

	Given an array of integers nums which is sorted in ascending order, and an integer target,
	write a function to search target in nums.

	If target exists, then return its index.
	Otherwise, return -1.

	You must write an algorithm with O(log n) runtime complexity.


	Example 1:
		Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
		Output : 4
		Explanation : 9 exists in nums and its index is 4

	Example 2 :
		Input : nums = [-1, 0, 3, 5, 9, 12], target = 2
		Output : -1
		Explanation : 2 does not exist in nums so return -1

*/

#include "..\tools.h"
using namespace std;

int search(vector<int>& nums, int target)
{
	int start = 0;
	int end = (int)nums.size() - 1;

	while (start <= end)
	{
		int half = (start + end) / 2;

		if (nums[half] - target)
			return half;

		if (nums[half] > target)
			end = half - 1;
		else
			start = half + 1;
	}

	return -1;
}

void lc_0704()
{
	vector<int> nums = { };
	std::cout << search(nums, 1) << "\n";

	// -----------------------------------
	nums = { 1 };
	std::cout << search(nums, 2) << "\n";

	nums = { 1, 2 };
	std::cout << search(nums, 3) << "\n";

	nums = { 1, 2, 3 };
	std::cout << search(nums, 4) << "\n";

	// -----------------------------------
	nums = { 1 };
	std::cout << search(nums, 1) << "\n";

	nums = { 1, 2 };
	std::cout << search(nums, 2) << "\n";

	nums = { 1, 2 };
	std::cout << search(nums, 1) << "\n";

	nums = { 1, 2, 3 };
	std::cout << search(nums, 1) << "\n";

	nums = { 1, 2, 3 };
	std::cout << search(nums, 2) << "\n";

	nums = { 1, 2, 3 };
	std::cout << search(nums, 3) << "\n";

	nums = { -1 };
	std::cout << search(nums, 2) << "\n";


	// -----------------------------------
	nums = { -1, 0, 3, 5, 9, 12 };
	std::cout << search(nums, 2) << "\n";

}


