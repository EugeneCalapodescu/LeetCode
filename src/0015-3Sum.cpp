/* LC-0015-3Sum.cpp

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.


Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.

    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.


*/

#include "..\tools.h"

using namespace std;

/* ------------------------------------------------------------------------- */
static string to_string(vector<int>& v)
{
    string res = "[";

    for (int n : v)
        res += to_string(n) + ", ";

    return res + "]";
}

static string to_string(vector<vector<int>>& v)
{
    string res = "[\n";

    for (auto n : v)
        res += to_string(n) + "\n";

    return res + "]";
}

/* ------------------------------------------------------------------------- */
/*
    Sort the array, then use two pointers, one at the beginning, the second at the end
    To eliminate the duplicates, I used a set

    A more optimal solution would be to eliminate the duplicates by increasing or decreasing the pointers, once we found a solution

*/

vector<vector<int>> threeSum(vector<int>& nums)
{
    // sort the array first
    std::sort(nums.begin(), nums.end());

    // two pointer strategy for each iteration
    std::set<std::vector<int>> set;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int p1 = i + 1;
        int p2 = nums.size() - 1;

        while (p1 < p2)
        {
            int sum = nums[i] + nums[p1] + nums[p2];

            if (sum == 0)
            {
                set.insert({ nums[i], nums[p1], nums[p2] });
                p1++;
                p2--;
            }
            else if (sum < 0)
                p1++;
            else
                p2--;

        }
    }

    vector<vector<int>> res;
    for (auto r : set)
        res.push_back(r);

    return res;
}

/* ------------------------------------------------------------------------- */
void lc_0015()
{
    vector<int> v = { -1,0,1,2,-1,-4 };
    // v = { -4,-1, -1, 0, 1, 2 };
    // v = { -2, 0, 1, 1, 2 };

    auto res = threeSum(v);

    std::cout << to_string(v) << to_string(res) << "\n";
}

