/* LC - 0049 - GroupAnagrams

Given an array of strings strs, group the
anagrams
together. You can return the answer in any order.



Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
    Input: strs = [""]
    Output: [[""]]

Example 3:
    Input: strs = ["a"]
    Output: [["a"]]


Another solution from leetcode
    - sort each string, so the key of the map becomes a string instead of a frequency map and it's faster

Note:
    map[n] always returns a value, because it inserts something if it doesnt find anything
    so everything can be written with less code when we create the frequency map

*/

#include "..\tools.h"

using namespace std;

/* -------------------------------------------------------------- */
std::map <char, int> getMap(const std::string& str)
{
    std::map<char, int> res;

    for (char c : str)
        res[c]++;

    return res;
}

/* -------------------------------------------------------------- */
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<map<char, int>, vector<string>> counter;

    for (auto s : strs)
    {
        auto m = getMap(s);

        auto found = counter.find(m);
        if (found == counter.end())
            counter[m] = { s };
        else
            counter[m].push_back(s);
    }

    vector<vector<string>> res;
    for (auto kv : counter)
        res.push_back(kv.second);

    return res;
}

/* -------------------------------------------------------------- */
static string print(vector<string>& strs)
{
    string res = "[";
    for (auto s : strs)
        res += s + " ";
    return res + "]";
}

static string print(vector<vector<string>>& v)
{
    string res = "[";
    for (auto s : v)
        res += print(s) + " ";
    return res + "]";
}

/* -------------------------------------------------------------- */
void lc_0049()
{
    vector<string> v = { "eat","tea","tan","ate","nat","bat" };
    auto res = groupAnagrams(v);
    std::cout << print(v) << ": " << print(res) << "!\n";
}
