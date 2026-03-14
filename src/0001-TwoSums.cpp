/*
    LC 1 Two Sum

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Use a map, to store the values already seen
    Search for (Target - current) in the map
*/


#include "..\tools.h"

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        int value = nums[i];

        auto found = map.find(target - value);
        if (found != map.end())
            return { found->second, i };

        map[value] = i;
    }

    return std::vector<int>();
}

void lc_0001()
{
    std::vector<int> v{ 2,7,11,15 };
    auto res = twoSum(v, 9);
}



