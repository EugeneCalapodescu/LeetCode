/* LC-0011-ContainerWithMostWater

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
Explanation:
    The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
    In this case, the max area of water (blue section) the container can contain is 49.

*/

#include "..\tools.h"

using namespace std;

/* ------------------------------------------------------------------------- */
static string print(vector<int>& v)
{
    string res = "[";

    for (int n : v)
        res += to_string(n) + ", ";

    return res + "]";
}

/* ------------------------------------------------------------------------- */
int maxArea(vector<int>& height)
{
    if (height.size() < 2)
        return 0;

    size_t p1 = 0;
    size_t p2 = height.size() - 1;

    size_t max_area = 0;
    while (p1 < p2)
    {
        size_t area = (p2 - p1) * std::min(height[p1], height[p2]);
        max_area = std::max(max_area, area);

        if (height[p1] < height[p2])
            p1++;
        else
            p2--;
    }

    return max_area;
}

/* ------------------------------------------------------------------------- */
void lc_0011()
{
    vector<int> v = { 1,8,6,2,5,4,8,3,7 };

    std::cout << print(v) << maxArea(v) << "\n";
}

