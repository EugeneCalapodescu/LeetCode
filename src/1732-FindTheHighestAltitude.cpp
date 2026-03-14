/* LC - 1732 - FindTheHighestAltitude

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n).
Return the highest altitude of a point.


Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.



*/

#include "..\tools.h"
using namespace std;

int largestAltitude(vector<int>& gain) {
    int sum = 0, max = 0;

    for (int n : gain)
    {
        sum += n;
        if (sum > max)
            max = sum;
    }

    return max;
}

void lc_1732()
{
    vector<int> gain = { -4,-3,-2,-1,4,3,2 };
    std::cout << largestAltitude(gain) << "\n";
}

