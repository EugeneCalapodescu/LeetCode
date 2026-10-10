/*
    The median is the middle value in a sorted list of integers. 
    For lists of even length, there is no middle value, so the median is the mean of the two middle values.

    For example:
        For arr = [1,2,3], the median is 2.
        For arr = [1,2], the median is (1 + 2) / 2 = 1.5

    Solution: use a multiset and a pointer
    Standard solution: 2 heaps, a small Max heap and a large small heap

*/

#include "..\tools.h"

using namespace std;

class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator mid;

    void addNum(int num) {
        ms.insert(num);

        size_t N = ms.size();
        if (N == 1)
        {
            mid = ms.begin();
            return;
        }

        if (N % 2 != 0)
        {
            if (num >= *mid)
                mid = std::next(mid);
        }
        else if (num < *mid)
        {
            mid = std::prev(mid);
        }
    }

    double findMedian() 
    {
        size_t N = ms.size();
        if (N % 2 != 0)
            return *mid;

        return (*mid + *std::next(mid)) / 2.0;
    }
};