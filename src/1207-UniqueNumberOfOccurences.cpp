/*

	LC 1207 Unique Number of Occurences

	Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

	Example 1:
		Input: arr = [1,2,2,1,1,3]
		Output: true
		Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

	Example 2:
		Input: arr = [1,2]
		Output: false


*/

#include "..\tools.h"
using namespace std;

bool uniqueOccurrences(vector<int>& arr)
{
	map<int, int> occurences;

	for (int n : arr)
		occurences[n]++;

	std::set<int> set;
	for (auto& kv : occurences)
		set.insert(kv.second);

	return occurences.size() == set.size();
}

void lc_1207()
{
	vector<int> nums = { 1,2,2,1,1,3 };
	cout << uniqueOccurrences(nums) << "\n";

	nums = { 1,2 };
	cout << uniqueOccurrences(nums) << "\n";

}


