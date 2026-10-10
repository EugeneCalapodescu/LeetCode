/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
However, you can buy it then immediately sell it on the same day. 
Also, you are allowed to perform any number of transactions 
but can hold at most one share of the stock at any time.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 7
*/

#include "..\tools.h"

using namespace std;

static int maxProfit(vector<int>& prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}


void lc_0122()
{
    vector<int> v{ 7, 1, 5, 3, 6, 4};
    cout << maxProfit(v) << "\n";

}
