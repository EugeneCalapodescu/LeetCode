/*
	Given an integer array nums of length n, you want to create an array ans of length 2n where 
	ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

*/

#include "..\tools.h"


std::vector<int> getConcatenation(std::vector<int>& nums) 
{
	std::vector<int> res(2 * nums.size());

	for (int i = 0; i < nums.size(); i++)
		res[i] = res[i + nums.size()] = nums[i];

	return res;
}

void lc_1929()
{
	std::vector<int> v{1, 2, 3};

	auto res = getConcatenation(v);
}