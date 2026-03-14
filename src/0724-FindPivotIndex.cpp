#include "..\tools.h"

using namespace std;

int pivotIndex(vector<int>& nums)
{
	int N = nums.size();

	vector<int> left_sums(N, 0);

	left_sums[0] = nums[0];
	for (int i = 1; i < N; i++)
		left_sums[i] = left_sums[i - 1] + nums[i];

	cout << to_string(left_sums) << "\n";

	vector<int> right_sums(N, 0);

	right_sums[N - 1] = nums[N - 1];
	for (int i = N - 2; i >= 0; i--)
		right_sums[i] = right_sums[i + 1] + nums[i];

std:;cout << to_string(right_sums) << "\n";

	for (int i = 0; i < N; i++)
	{
		int left = (i == 0) ? 0 : left_sums[i - 1];
		int right = (i == N - 1) ? 0 : right_sums[i + 1];
		if (left == right)
			return i;
	}

	return -1;
}


void lc_0724()
{
	vector<int> nums = { 1, 7, 3, 6, 5, 6 };

	cout << pivotIndex(nums);
}