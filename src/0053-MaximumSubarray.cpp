#include "..\tools.h"

using namespace std;

int maxSubArray(vector<int>& nums) 
{
	if (nums.empty())
		return 0;

	int max_sum = nums[0];
	int curr_sum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		curr_sum = std::max(curr_sum, 0);
		curr_sum += nums[i];
		max_sum = std::max(curr_sum, max_sum);
	}

	return max_sum;
}

void lc_0053()
{
	vector<int> v{ 2,-3,4,-2,2,1,-1,4 };
	vector<int> v2{ 2, -3, 4, -2, 2, 1, -1, 4 };
	cout << maxSubArray(v) << "\n";
	cout << maxSubArray(v2) << "\n";

}