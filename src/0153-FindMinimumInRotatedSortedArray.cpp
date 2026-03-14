#include "..\tools.h"

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
  For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.
    You must write an algorithm that runs in O(log n) time.

Solution: binary search between two pointers, left and right
    if nums[left> < nums[right} then it's the right side that contains the inversion
    otherwise it's on the left side
*/

int find_min(std::vector<int>& nums, int left, int right)
{
    if (left == right)
        return nums[left];

    if (left + 1 == right)
        return std::min(nums[left], nums[right]);

    if (nums[left] < nums[right])
        return nums[left];

    int mid = left + (right - left) / 2;

    if (nums[left] < nums[mid])
        return find_min(nums, mid, right);

    return find_min(nums, left, mid);
}

int findMin(std::vector<int>& nums)
{
    return find_min(nums, 0, nums.size() - 1);
}

// better, iterative version, with left and right pointers
// but tricky, need to compare with the right, otherwise it doesnt works
// at the end of the loop, left points to the min
int findMin_loop(std::vector<int>& nums)
{
    int l = 0, r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[r])
            r = m;
        else
            l = m + 1;
    }

    return nums[l];
}

void lc_0153()
{
    std::vector<int> v = { 4,5,6,7,0,1,2 };
    std::cout << findMin(v) << "\n";

    v = { 4,5,6,7 };
    std::cout << findMin(v) << "\n";

}
