/*

	LC 746 -  Min Cost Climbing Stairs

	You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
	Once you pay the cost, you can either climb one or two steps.

	You can either start from the step with index 0, or the step with index 1.

	Return the minimum cost to reach the top of the floor.


	Example 1:
		Input: cost = [10,15,20]
		Output: 15
		Explanation: You will start at index 1.
		- Pay 15 and climb two steps to reach the top.
		The total cost is 15.

	Example 2:
		Input: cost = [1,100,1,1,1,100,1,1,100,1]
		Output: 6
		Explanation: You will start at index 0.
		- Pay 1 and climb two steps to reach index 2.
		- Pay 1 and climb two steps to reach index 4.
		- Pay 1 and climb two steps to reach index 6.
		- Pay 1 and climb one step to reach index 7.
		- Pay 1 and climb two steps to reach index 9.
		- Pay 1 and climb one step to reach the top.
		The total cost is 6.
*/


#include "..\tools.h"
using namespace std;

int minCostClimbingStairs(vector<int>& cost, int i, vector<int>& dp)
{
	if (i >= cost.size())
		return 0;

	if (dp[i] != -1)
		return dp[i];

	int n1 = minCostClimbingStairs(cost, i + 1, dp);
	int n2 = minCostClimbingStairs(cost, i + 2, dp);

	return dp[i] = cost[i] + min(n1, n2);
}


int minCostClimbingStairs(vector<int>& cost)
{
	vector<int> dp(cost.size(), -1);
	return min(minCostClimbingStairs(cost, 0, dp), minCostClimbingStairs(cost, 1, dp));
}


void lc_0746()
{
	vector<int> nums = {};
	printf("%d\n", minCostClimbingStairs(nums));

	nums = { 1 };
	printf("%d\n", minCostClimbingStairs(nums));

	nums = { 10,15,20 };
	printf("%d\n", minCostClimbingStairs(nums));

	nums = { 1,100,1,1,1,100,1,1,100,1 };
	printf("%d\n", minCostClimbingStairs(nums));

}