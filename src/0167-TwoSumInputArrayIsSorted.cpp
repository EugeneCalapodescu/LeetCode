/* LC - 0167 - TwoSumInputArrayIsSorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.


Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
    Input: numbers = [-1,0], target = -1
    Output: [1,2]
    Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

*/

#include "..\tools.h"
using namespace std;

vector<int> twoSum_sorted_array(vector<int>& numbers, int target)
{
    if (numbers.size() < 2)
        return { -1, -1 };

    int p1 = 0;
    int p2 = numbers.size() - 1;

    while (p2 > p1)
    {
        int sum = numbers[p1] + numbers[p2];

        if (sum == target)
            return { p1 + 1, p2 + 1 };

        if (sum < target)
            p1++;
        else
            p2--;
    }

    return { -1, -1 };
}

void lc_0167()
{
    vector<int> v = { 2,7,11,15 };
    auto res = twoSum_sorted_array(v, 18);
    std::cout << to_string(v) << to_string(res) << "\n";
}

