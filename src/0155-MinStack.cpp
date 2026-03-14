/* LC-0155-MinStack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

*/

#include "..\tools.h"

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        if (stack.empty())
            stack.push({ val, val });
        else
            stack.push({ val, std::min(val, stack.top().second) });
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.top().first;
    }

    int getMin() {
        return stack.top().second;
    }

private:
    stack<pair<int, int>> stack;

};


void lc_0155()
{

    std::cout << "\n";
}

