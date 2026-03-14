#include "..\tools.h"

/*
	Given a binary array nums, return the maximum number of consecutive 1's in the array.
	Example 1:

	Input: nums = [1,1,0,1,1,1]
	Output: 3
	Explanation: The first two digits or the last three digits are consecutive 1s.
	The maximum number of consecutive 1s is 3.

*/

int findMaxConsecutiveOnes(std::vector<int>& nums)
{
	int max = 0;
	int current = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
			current = 0;
		else if (++current > max)
			max = current;
	}

	return max;
}


void lc_0485()
{

}
