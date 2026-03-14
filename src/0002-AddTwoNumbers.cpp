/*
	LC 2 Add Two numbers represented by linked lists

	You are given two non-empty linked lists representing two non-negative integers. 
	The digits are stored in reverse order, and each of their nodes contains a single digit. 
	Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.

*/

#include "..\tools.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *result = NULL, *last = NULL;

    int reminder = 0;
    while (l1 || l2 || reminder)
    {
        int sum = reminder;

        if (l1)
            sum += l1->val;

        if (l2)
            sum += l2->val;

        reminder = sum / 10;
        
        auto tmp = new ListNode(sum % 10);
        if (last)
        {
            last->next = tmp;
            last = tmp;
        }
        else
        {
            result = last = tmp;
        }

        if(l1)
            l1 = l1->next;
        
        if(l2)
            l2 = l2->next;
    }

    return result;
}


void lc_0002()
{
    ListNode* n11 = new ListNode(9);
    ListNode* n12 = new ListNode(1, n11);

    ListNode* n21 = new ListNode(8);
    ListNode* n22 = new ListNode(2, n21);


    addTwoNumbers(n12, n22);
}

