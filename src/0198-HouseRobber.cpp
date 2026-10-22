/*
You are given an integer array nums where nums[i] represents the amount of money the ith house has. 
The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.

You are planning to rob money from the houses, but you cannot rob two adjacent houses 
because the security system will automatically alert the police if two adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.

Example 1:
	Input: nums = [1,1,3,3]
	Output: 4


Idea:
	keep track of the max you can get at n-1 and n-2

*/
#include "..\tools.h"

using namespace std;

static int rob(vector<int>& nums) 
{
	int p1 = 0;
	int p2 = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		int temp = std::max(p1 + nums[i], p2);
		p1 = p2;
		p2 = temp;
	}

	return p2;

}

void lc_0198()
{
	vector<int> v{ 1, 1, 3, 3 };

	std::cout << rob(v);
}