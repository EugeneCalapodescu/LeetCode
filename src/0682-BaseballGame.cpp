/*
You are keeping the scores for a baseball game with strange rules.
At the beginning of the game, you start with an empty record.
Given a list of strings operations, where operations[i] is the ith operation
you must apply to the record and is one of the following:
    An integer x: Record a new score of x.
    '+': Record a new score that is the sum of the previous two scores.
    'D': Record a new score that is the double of the previous score.
    'C': Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.


Solution: classical polish expression

We could eventually compute the result on the fly, inside the main loop
That would avoid the last loop

*/

#include "..\tools.h"

int calPoints(std::vector<std::string>& operations)
{
    std::stack<int> stack;
    for (auto& o: operations)
    {
        if (o == "C" && stack.size() > 0)
        {
            stack.pop();
        }
        else if (o == "D" && stack.size() >= 1)
        {
            stack.push(stack.top() * 2);
        }
        else if (o == "+" && stack.size() >= 2)
        {
            int top = stack.top();
            stack.pop();
            int n = top + stack.top();
            stack.push(top);
            stack.push(n);
        }
        else
        {
            stack.push(std::atoi(o.c_str()));
        }
    }

    int res = 0;
    while (!stack.empty())
    {
        res += stack.top();
        stack.pop();
    }

    return res;
}

void lc_0682()
{
    std::vector<std::string> v{ "1","2","+","C","5","D" };
    std::cout << calPoints(v) << "\n";
}