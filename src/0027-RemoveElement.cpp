/*
 * remove the elements in place that are equal to some value (V), return the number of items left (K)
 * elements can be moved, first elements in the remaining vector contain the elements that are not equal to the value removed
 * the last elements after K do not matter
 *
 * loop on the array with 2 pointers, i is the normal loop
 * pos is the position of the next write, if the v[i] != val
 */

#include "..\tools.h"

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	int pos = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != val)
		{
			nums[pos] = nums[i];
			pos++;
		}
	}

	return pos;
}

static void print(const std::vector<int>& v, int size = -1)
{
	if (size == -1)
		size = v.size();

	for (int i = 0; i < size; i++)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}


void lc_0027()
{
	vector<int> v = { 1, 2, 3, 4, 5 };

	int n = removeElement(v, 3);

	cout << n << " elements left\n";
	print(v, n);

	v = { 1, 2, 3, 2, 5 };
	n = removeElement(v, 2);

	cout << n << " elements left\n";
	print(v, n);

}