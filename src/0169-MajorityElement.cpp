#include "..\tools.h"
/*
* The majority element is the element that appears more than ⌊n / 2⌋ times.
* Assuming it always exists
*
* first idea, use a map, then iterate on the map and get the greatest
* maybe we can do something to stop before the end, we know if one freq is > n/2 then we are done already?
*/

int majorityElement(std::vector<int>& nums)
{
	std::unordered_map<int, int> res;
	for (int n : nums)
		res[n] = res[n] + 1;

	std::pair<int, int> max;
	for (auto& kv : res)
	{
		if (kv.second > max.second)
			max = kv;
	}

	return max.first;
}

void lc_0169()
{
	std::vector<int> v = { 1, 2, 2 };
	std::cout << majorityElement(v) << "\n";

	v = { 1, 1, 1, 2, 2 };
	std::cout << majorityElement(v) << "\n";
}