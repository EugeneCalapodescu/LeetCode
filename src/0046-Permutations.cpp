/*

	LC 46 permutations

	Given an array nums of distinct integers, return all the possible permutations.You can return the answer in any order.

	Example 1:
		Input: nums = [1, 2, 3]
		Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

	Example 2 :
		Input : nums = [1, 2]
		Output : [[1, 2], [2, 1]]

	Example 3 :
		Input : nums = [1]
		Output : [[1]]


	LeetCode Solution:

	void shuffle(vector<int>&nums,vector<vector<int>>&ans,int i)
		{
			if(i == nums.size())
			{
				ans.push_back(nums);
				return;
			}

			for(int j=i;j<nums.size();j++)
			{
				swap(nums[i],nums[j]);
				shuffle(nums,ans,i+1);
				swap(nums[i],nums[j]);
			}
		}

		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>>ans;
			shuffle(nums,ans,0);
			return ans;
		}
*/

#include "..\tools.h"
using namespace std;

vector<vector<int>> permute(vector<int>& nums, int N)
{
	if (N == 0)
		return { {} };

	auto temp = permute(nums, N - 1);

	vector<vector<int>> result;
	for (auto arr : temp)
	{
		arr.push_back(nums[N - 1]);
		result.push_back(arr);

		for (size_t i = arr.size() - 1; i > 0; i--)
		{
			std::swap(arr[i - 1], arr[i]);
			result.push_back(arr);
		}
	}

	return result;
}

vector<vector<int>> permute(vector<int>& nums)
{
	if (nums.size() <= 1)
		return { nums };

	return permute(nums, nums.size());
}

static void print(const std::vector<std::vector<int>>& res)
{
	printf("{\n");
	for (auto v : res)
	{
		for (auto n : v)
			printf("%d ", n);
		printf("\n");
	}
	printf("}\n");
}

void lc_0046()
{
	std::vector<int> nums = {};
	print(permute(nums));

	nums = { 1 };
	print(permute(nums));

	nums = { 1, 2 };
	print(permute(nums));

	nums = { 1, 2, 3 };
	print(permute(nums));

	nums = { 1, 2, 3, 4 };
	print(permute(nums));

}
