/*

    LC 26 Remove Duplicates from sorted array

    Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
    each unique element appears only once. The relative order of the elements should be kept the same.

    Since it is impossible to change the length of the array in some languages, you must instead
    have the result be placed in the first part of the array nums. More formally,
    if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
    It does not matter what you leave beyond the first k elements.

    Return k after placing the final result in the first k slots of nums.

    Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

*/

#include "..\tools.h"

using namespace std;

static void print(const vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << std::endl;
}

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();

    int pos = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
            nums[pos++] = nums[i];
    }

    return pos;

}

void lc_0026()
{
    vector<int> nums1 = { 1, 1, 2, 2, 2, 3, 4, 5, 5, 5 };

    print(nums1);
    printf("%d\n", removeDuplicates(nums1));
    print(nums1);
}
