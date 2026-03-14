/*

    LC 907 Sum Of Subarrays Minimums

    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
    Since the answer may be large,  return the answer modulo 109 + 7.

    Example 1:

    Input: arr = [3,1,2,4]
    Output: 17
    Explanation:
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.

*/



#include "..\tools.h"
using namespace std;

int sumSubarrayMins_N2(vector<int>& arr)
{
    if (arr.size() == 0)
        return 0;

    if (arr.size() == 1)
        return arr[0];


    long long sum = 0;

    for (int start = 0; start < arr.size(); start++)
    {
        int min = arr[start];
        sum += min;

        for (int end = start + 1; end < arr.size(); end++)
        {
            if (arr[end] < min)
                min = arr[end];
            sum += min;
        }
    }

    return sum % (1000000000 + 7);
}

vector<int>prev_greater(vector<int>& arr)
{
    vector<int> result;
    stack<int> stack;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!stack.empty() && arr[stack.top()] < arr[i])
            stack.pop();

        if (!stack.empty())
            result.push_back(stack.top());
        else
            result.push_back(i);

        stack.push(i);
    }

    return result;
}

vector<int>next_greater(vector<int>& arr)
{
    vector<int> result;
    stack<int> stack;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() && arr[stack.top()] < arr[i])
            stack.pop();

        if (!stack.empty())
            result.push_back(stack.top());
        else
            result.push_back(i);

        stack.push(i);
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int>prev_smaller(vector<int>& arr)
{
    vector<int> result;
    stack<int> stack;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!stack.empty() && arr[stack.top()] > arr[i])
            stack.pop();

        if (!stack.empty())
            result.push_back(stack.top());
        else
            result.push_back(i);

        stack.push(i);
    }

    return result;
}

vector<int>next_smaller(vector<int>& arr)
{
    vector<int> result;
    stack<int> stack;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
            stack.pop();

        if (!stack.empty())
            result.push_back(stack.top());
        else
            result.push_back(i);

        stack.push(i);
    }

    reverse(result.begin(), result.end());

    return result;
}

static void print(vector<int>& arr, std::string name)
{
    printf("%s\n", name.c_str());
    for (auto i : arr)
        printf("%d ", i);
    printf("\n");
}

int sumSubarrayMins(vector<int>& arr)
{
    auto prev = prev_smaller(arr);
    auto next = next_smaller(arr);

    print(arr, "arr");
    print(prev, "prev");
    print(next, "next");

    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int l = 0, r = 0;

        if (prev[i] == i)
            l = i + 1;
        else
            l = i - prev[i];

        if (next[i] == i)
            r = arr.size() - i;
        else
            r = next[i] - i;

        long t = l * r;

        printf("%d: (%d) l=%d, r=%d t=%d\n", i, arr[i], l, r, t);
        sum += t * arr[i];
    }

    return sum % (1000000000 + 7);
}

void lc_0907()
{
    std::vector<int> arr1 = { 71,55,82,55 };
    printf("%d\n", sumSubarrayMins(arr1));

    std::vector<int> arr2 = { 3,1,2,4 };
    printf("%d\n", sumSubarrayMins(arr2));

    std::vector<int> arr3 = { 11, 81, 94, 43, 3 };
    printf("%d\n", sumSubarrayMins(arr3));

}