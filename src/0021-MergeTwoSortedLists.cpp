/*

	LC 21 Merge Two sorted Lists

	You are given the heads of two sorted linked lists list1 and list2.
	Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
	Return the head of the merged linked list.

	Example 1:
		Input: list1 = [1,2,4], list2 = [1,3,4]
		Output: [1,1,2,3,4,4]

	Solution
		Use a dummy node to make insertions on the head simpler
		merge while both lists have items, and at the end just append whatever list still have nodes
*/

#include "..\tools.h"

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
	ListNode* result = new ListNode();
	ListNode* last = result;

	while (list1 && list2)
	{
		if (list1->val <= list2->val)
		{
			last->next = list1;
			list1 = list1->next;
		}
		else
		{
			last->next = list2;
			list2 = list2->next;
		}

		last = last->next;
		last->next = NULL;
	}

	if (list2 == NULL)
		last->next = list1;
	else
		last->next = list2;

	return result->next;
}

ListNode* mergeTwoListsRecusrive(ListNode* l1, ListNode* l2) {
	if (!l1)
		return l2;

	if (!l2)
		return l1;

	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoListsRecusrive(l1->next, l2);
		return l1;
	}

	l2->next = mergeTwoListsRecusrive(l1, l2->next);

	return l2;
}


void lc_0021()
{
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(2);
	list1->next->next = new ListNode(4);

	ListNode* list2 = new ListNode(1);
	list2->next = new ListNode(3);
	list2->next->next = new ListNode(4);

	auto list3 = mergeTwoLists(list1, list2);

	list1 = new ListNode(1);
	list2 = NULL;

	list3 = mergeTwoLists(list1, list2);


}
