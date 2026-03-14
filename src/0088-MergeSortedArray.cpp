#include "..\tools.h"

/*
 * merge two sorted arrays
 * store the results inside the firts array which already has the space
 *
 * Start from the back and insert the biggest of the numbers and just move the pointers back
 * Could do with pointers for speed
 * Could remove the n-1 that we do at each loop
 * Could use -- inside the affectations if we wanted to remove a few lines nums9[back--] = numsx[nx--];
 *
 * I would rather spec the function to take just two arrays and handle the additional size itself
 */

using namespace std;

static void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2)
{
	int back = nums1.size() - 1;

	while (n2 > 0)
	{
		if (n1 > 0 && nums1[n1 - 1] > nums2[n2 - 1])
		{
			nums1[back] = nums1[n1 - 1];
			n1--;
		}
		else
		{
			nums1[back] = nums2[n2 - 1];
			n2--;
		}
		back--;
	}

}

static void print(const std::vector<int>& v)
{
	for (auto i : v)
		std::cout << i << " ";

	std::cout << std::endl;
}

void lc_0088()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	merge(nums1, 3, nums2, 3);
	print(nums1);

	nums1 = { 0, 0, 0 };
	nums2 = { 1, 2, 3 };
	merge(nums1, 0, nums2, 3);
	print(nums1);

	nums1 = { 1, 2, 3 };
	nums2 = {};
	merge(nums1, 3, nums2, 0);
	print(nums1);

}

