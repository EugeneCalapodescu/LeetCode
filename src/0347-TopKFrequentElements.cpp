/* LC - 0347 - TopKFrequentElements


Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Example 2:
    Input: nums = [1], k = 1
    Output: [1]


Note: look at the std::priority_queue, which would have avoided a sort

*/

#include "..\tools.h"

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freq;

    for (int n : nums)
        freq[n]++;

    std::vector<std::pair<int, int>> v;
    for (auto kv : freq)
        v.push_back(kv);

    std::sort(v.begin(), v.end(), [](auto& left, auto& right) {return left.second < right.second; });

    std::vector<int> res;
    for (int i = 0; i < k && i < v.size(); i++)
        res.push_back(v[v.size() - 1 - i].first);

    return res;
}

void lc_0347()
{
    vector<int> v = { 1,1,1,2,2,3 };
    auto res = topKFrequent(v, 2);
    std::cout << to_string(v) << " " << to_string(res) << "\n";
}
