/*

	LC 1235 Maximum Profit in Job Scheduling

		We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

		You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that
		there are no two jobs in the subset with overlapping time range.

		If you choose a job that ends at time X you will be able to start another job that starts at time X.


	Example 1:
		Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
		Output: 120
		Explanation: The subset chosen is the first and fourth job.
		Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

	Example 2:
		Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
		Output: 150
		Explanation: The subset chosen is the first, fourth and fifth job.
		Profit obtained 150 = 20 + 70 + 60.

*/
#include "..\tools.h"

using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);

void lc_1235()
{
	vector<int> startTime = { 1, 2, 3, 3 };
	vector<int> endTime = { 3, 4, 5, 6 };
	vector<int> profit = { 50, 10, 40, 70 };

	printf("%d\n", jobScheduling(startTime, endTime, profit));
}

/* -------------------------------------------------------------------------------------------------- */
int jobScheduling_naive(vector<int>& startTime, vector<int>& endTime, vector<int>& profit, int start)
{
	int max_profit = 0;
	for (int i = 0; i < startTime.size(); i++)
	{
		if (startTime[i] >= start)
		{
			int p = profit[i] + jobScheduling_naive(startTime, endTime, profit, endTime[i]);
			if (p > max_profit)
				max_profit = p;
		}
	}

	return max_profit;
}

/* -------------------------------------------------------------------------------------------------- */
struct Job
{
	int start;
	int end;
	int value;

	Job(int s, int e, int v) :
		start(s), end(e), value(v)
	{

	}

	bool operator<(const Job& o) const
	{
		return end < o.end;
	}
};

/* -------------------------------------------------------------------------------------------------- */
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
	// return jobScheduling_naive(startTime, endTime, profit, -1);

	vector<Job> jobs;

	for (int i = 0; i < startTime.size(); i++)
		jobs.push_back(Job(startTime[i], endTime[i], profit[i]));

	std::sort(jobs.begin(), jobs.end());

	std::vector<int> dp(jobs.size(), 0);
	dp[0] = jobs[0].value;

	for (int i = 1; i < jobs.size(); i++)
	{
		dp[i] = max(jobs[i].value, dp[i - 1]);
		for (int j = i - 1; j >= 0; j--)
		{
			if (jobs[j].end <= jobs[i].start)
			{
				dp[i] = max(dp[i], jobs[i].value + dp[j]);
				break;
			}
		}
	}

	int res = -1;
	for (int i = 0; i < jobs.size(); i++)
	{
		res = max(res, dp[i]);
	}

	return res;
}
