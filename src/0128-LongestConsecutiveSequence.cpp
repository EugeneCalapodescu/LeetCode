/* LC-0128-LongestConsecutiveSequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

*** You must write an algorithm that runs in O(n) time.

Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9


*/



#include "..\tools.h"

using namespace std;


// sort solution 
int longestConsecutive_sort(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;

    std::sort(nums.begin(), nums.end());

    int current = 1;
    int best = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;

        if (nums[i] == nums[i - 1] + 1)
        {
            current++;
            if (current > best)
                best = current;
        }
        else
        {
            current = 1;
        }
    }

    return best;
}

// set solution 
int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> set;
    for (int n : nums)
        set.insert(n);

    int best = 0;
    for (int n : set)
    {
        // if we do not have N-1 in the set, then N is the beginning of a sequence
        // so se check how long this sequence is, i.e, check if N+1 is in the set, N+2, N+3, etc
        if (set.find(n - 1) == set.end())
        {
            int current = 0;
            while (set.find(n + current) != set.end())
                current++;

            if (current > best)
                best = current;
        }
    }

    return best;
}


static string print(vector<int>& nums)
{
    string res = "[";
    for (int n : nums)
        res += to_string(n) + " ";
    return res + "]";
}

void lc_0128()
{
    vector<int> v = { 1, 2, 3, 1 };
    std::cout << print(v) << longestConsecutive(v) << "\n";
}
