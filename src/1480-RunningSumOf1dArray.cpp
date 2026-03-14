#include "..\tools.h"

using namespace std;

vector<int> runningSum(vector<int>& nums)
{
	vector<int> sum(nums.size(), 0);

	sum[0] = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		sum[i] = sum[i - 1] + nums[i];
	}

	return sum;

}

static void print(const vector<int>& nums)
{
	for (auto i : nums)
		cout << i << " ";
	cout << "\n";
}

void lc_1480()
{
	vector<int> nums = { 1, 2, 3, 4 };
	auto sums = runningSum(nums);
	print(sums);

	nums = { 1, 1, 1, 1, 1 };
	sums = runningSum(nums);
	print(sums);

}