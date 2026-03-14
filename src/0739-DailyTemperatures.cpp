/* LC-0739-DailyTemperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that
answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.


Example 1:
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

Example 2:
    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

Example 3:
    Input: temperatures = [30,60,90]
    Output: [1,1,0]

*/

#include "..\tools.h"

using namespace std;

/* ------------------------------------------------------------------------- */
vector<int> dailyTemperatures(vector<int>& temperatures)
{
    vector<int> res(temperatures.size(), 0);
    stack<pair<int, int>> stack;

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (stack.size() > 0 && stack.top().second < temperatures[i])
        {
            res[stack.top().first] = i - stack.top().first;
            stack.pop();
        }
        stack.push({ i, temperatures[i] });
    }

    return res;
}


/* ------------------------------------------------------------------------- */
void lc_0739()
{
    vector<int> v = { 73,74,75,71,69,72,76,73 };
    vector<int> res = dailyTemperatures(v);
    std::cout << "\n";
}

