/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, 
adjacent houses have a security system connected, and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Idea: this is the same as LC 198 House robber, just that 0 and n-1 are connected
    You could reuse house robber 1 and run it twice, and take the max of hr( 0, n-2 ) and hr( 1, n-1 )

Solution: like house robber 1 but compute both states in one loop
*/

#include "..\tools.h"
using namespace std;

static int rob(vector<int>& nums)
{
    size_t n = nums.size();
    if (n == 1) 
        return nums[0];

    if (n == 2) 
        return std::max(nums[0], nums[1]);

    // Includes House 0
    int v1_rob1 = 0, v1_rob2 = 0;

    // Excludes House 0 (Runs from index 1 to n-1)
    int v2_rob1 = 0, v2_rob2 = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i < n - 1) {
            int next_a = std::max(v1_rob1 + nums[i], v1_rob2);
            v1_rob1 = v1_rob2;
            v1_rob2 = next_a;
        }

        if (i > 0) {
            int next_b = std::max(v2_rob1 + nums[i], v2_rob2);
            v2_rob1 = v2_rob2;
            v2_rob2 = next_b;
        }
    }

    return std::max(v1_rob2, v2_rob2);
}

void lc_0213()
{
    vector<int> v1{ 2,3,2 };
    std::cout << rob(v1) << "\n";
}