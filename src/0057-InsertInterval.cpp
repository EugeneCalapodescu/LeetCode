/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents 
the start and the end time of the ith interval. intervals is initially sorted in ascending order by start_i.

You are given another interval newInterval = [start, end].

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i 
and also intervals still does not have any overlapping intervals. You may merge the overlapping intervals if needed.

Return intervals after adding newInterval.

Note: Intervals are non-overlapping if they have no common point. 
For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.

Example 1:
	Input: intervals = [[1,3],[4,6]], newInterval = [2,5]
	Output: [[1,6]]
*/

#include "..\tools.h"
using namespace std;

static vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
	vector<vector<int>> res;

	size_t i = 0;
	size_t N = intervals.size();

	// first add the ones that are smaller
	while (i < N && intervals[i][1] < newInterval[0])
	{
		res.push_back(intervals[i]);
		i++;
	}

	// then merge if needed and add the new interval
	while (i < N && intervals[i][0] <= newInterval[1]) 
	{
		newInterval[0] = std::min(newInterval[0], intervals[i][0]);
		newInterval[1] = std::max(newInterval[1], intervals[i][1]);
		i++;
	}

	res.push_back(newInterval);

	// then add the remaining, greater intervals
	while (i < N)
	{
		res.push_back(intervals[i]);
		i++;
	}

	return res;
}


void lc_0057()
{
	vector<vector<int>> v{ {1, 3}, {4, 6} };
	vector<int> n{ 1, 6 };
	auto res = insert(v, n);
}


