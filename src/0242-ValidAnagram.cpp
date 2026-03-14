/* LC-0242-ValidAnagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

Example 2:
    Input: s = "rat", t = "car"
    Output: false

*/

/*
* We could also just sort and compare the strings
  Nice solution from leetcode, one single loop, and an array

    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m)
            return false;

        int str[26] = {0};

        for(int i = 0; i < n; i++)
        {
            str[s[i] - 'a']++;
            str[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++)
            if(str[i] != 0)
                return false;

        return true;
*/

#include "..\tools.h"
using namespace std;

bool isAnagram(string s, string t)
{
    map<char, int> ms, mt;

    for (int i = 0; i < s.size(); i++)
        ms[s[i]]++;

    for (int i = 0; i < t.size(); i++)
        mt[s[i]]++;

    return ms == mt;
}

void lc_0242()
{
    std::cout << isAnagram("car", "rac") << "\n";
}

