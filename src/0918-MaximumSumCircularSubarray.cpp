/*
	Given a circular integer array nums of length n, 
	return the maximum possible sum of a non-empty subarray of nums.

	A circular array means the end of the array connects to the beginning 
	of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] 
	and the previous element of nums[i] is nums[(i - 1 + n) % n].

	A subarray may only include each element of the fixed buffer nums at most once. 
	Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], 
	there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


	We compute a global min, a global max and a sum in one go
	if the max is without looping then it's the g_max that we computed in one run
	Otherwise, if the max is by looping then its its value is total - g_min
	So we return the greater of the two

	edge case if the total max is negative

*/

#include "..\tools.h"

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {

	if (nums.size() == 0)
		return 0;

	int g_min = nums[0];
	int g_max = nums[0];

	int c_min = 0; 
	int c_max = 0;
	int total = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		total += nums[i];

		c_max = std::max(c_max + nums[i], nums[i]);
		c_min = std::min(c_min + nums[i], nums[i]);

		if (c_max > g_max)
			g_max = c_max;

		if (c_min < g_min)
			g_min = c_min;
	}

	if (g_max > 0)
		return std::max(g_max, total - g_min);

	return g_max;
}

void lc_0918()
{
	vector<int> v{ 5, -1, 3 };
	std::cout << maxSubarraySumCircular(v) ;
}