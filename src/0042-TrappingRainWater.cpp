/* LC-0042-TrappingRainWater.cpp

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
Explanation:
    The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
    In this case, 6 units of rain water (blue section) are being trapped.

          #
      #   ##  #
    # ## #### ##
   -------------
   0102101321021

Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9

         #
    #....#
    #..#.#
    ##.###
    ##.###
    420325
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
/* Solution 1:
 *    compute two arrays, containings
 *       max of the wall to the left
 *       max of the wall to the right
 *    then loop the input array and for each index, the water stored is equal to
 *       min(L,R) - height[i]
 */
int trap(vector<int>& height)
{
    if (height.size() <= 2)
        return 0;

    int N = (int)height.size();
    vector<int> L(N), R(N);

    L[0] = 0;
    for (int i = 1; i < N; i++)
        L[i] = std::max(L[i - 1], height[i - 1]);

    R[height.size() - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
        R[i] = std::max(height[i + 1], R[i + 1]);

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += max(0, min(L[i], R[i]) - height[i]);

    return sum;
}

/* ------------------------------------------------------------------------- */
void lc_0042()
{
    vector<int> v{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    v = { 4,2,0,3,2,5 };
    std::cout << print(v) << trap(v) << "\n";
}

