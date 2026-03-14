/*

121. Best Time to Buy and Sell Stock


	You are given an array prices where prices[i] is the price of a given stock on the ith day.
	You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
	Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

	Example 1:
		Input: prices = [7,1,5,3,6,4]
		Output: 5
		Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
		Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

	Example 2:
		Input: prices = [7,6,4,3,1]
		Output: 0
		Explanation: In this case, no transactions are done and the max profit = 0.

	Solution: at each step, the best we can do is to check the current step - the previous minimum
*/

#include "..\tools.h"
using namespace std;

int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;

	int min_price = prices[0];
	int profit = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		profit = max(profit, prices[i] - min_price);
		min_price = min(min_price, prices[i]);
	}

	return profit;
}

void lc_0121()
{
	vector<int> nums = { };
	cout << maxProfit(nums) << "\n";

	nums = { 1 };
	cout << maxProfit(nums) << "\n";

	nums = { 1, 2 };
	cout << maxProfit(nums) << "\n";

	nums = { 2, 1 };
	cout << maxProfit(nums) << "\n";

	nums = { 7,1,5,3,6,4 };
	cout << maxProfit(nums) << "\n";

}