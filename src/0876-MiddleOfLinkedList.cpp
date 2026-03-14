/*

	Given the head of a singly linked list, return the middle node of the linked list.

	If there are two middle nodes, return the second middle node.



	Example 1:
		Input: head = [1, 2, 3, 4, 5]
		Output : [3, 4, 5]
		Explanation : The middle node of the list is node 3.

	Example 2 :
			Input : head = [1, 2, 3, 4, 5, 6]
			Output : [4, 5, 6]
			Explanation : Since the list has two middle nodes with values 3 and 4, we return the second one.

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


ListNode* middleNode(ListNode* head)
{
	if (!head)
		return NULL;

	vector<ListNode*> v;

	for (auto p = head; p; p = p->next)
		v.push_back(p);

	return v[v.size() / 2];
}

ListNode* middleNodeFastSlow(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;

	if (head == nullptr || head->next == nullptr)
		return head;

	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void lc_0876()
{
	ListNode* list = NULL;
	auto middle = middleNode(list);

	list = new ListNode(1);
	middle = middleNode(list);

	list = new ListNode(1);
	list->next = new ListNode(2);
	middle = middleNode(list);

	list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	middle = middleNode(list);

}



