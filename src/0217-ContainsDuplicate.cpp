/* LC-0217-ContainsDuplicate.cpp

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
    Input: nums = [1,2,3,1]
    Output: true
Explanation:
    The element 1 occurs at the indices 0 and 3.

Example 2:
    Input: nums = [1,2,3,4]
    Output: false
Explanation:
    All elements are distinct.

Example 3:
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true

*/

#include "..\tools.h"
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    unordered_set<int> uniques;

    for (int n : nums)
    {
        if (uniques.find(n) != uniques.end())
            return true;

        uniques.insert(n);
    }
    return false;
}

void lc_0217()
{
    vector<int> v = { 1, 2, 3, 4, 1, 6 };
    std::cout << containsDuplicate(v);
}
