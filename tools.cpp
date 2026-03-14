#include "tools.h"

/* ------------------------------------------------------------------------- */
std::string to_string(std::vector<int>& v)
{
    std::string res = "[";

    for (int n : v)
        res += std::to_string(n) + ", ";

    return res + "]";
}


std::string to_string(std::vector<std::string>& v)
{
    std::string res = "[";
    for (auto s : v)
        res += s + " ";
    return res + "]";
}