#include "..\tools.h"

/*
 * Remove nth node from end of list
 * Use two pointers, one starts with n moves ahead, then both advance one by one
 * when the first hits the end, the second is n nodes from the end of the list
 *
 * implementatin trick: use a dummy node before the head of the actual list
 * this handles the cases where we delete the head and removes the need to have the previous value
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode dummy(0, head);
	ListNode* slow = &dummy;
	ListNode* fast = head;

	for (int i = 0; i < n; i++)
		fast = fast->next;

	while (fast != nullptr)
	{
		slow = slow->next;
		fast = fast->next;
	}

	ListNode* nodeToDelete = slow->next;
	slow->next = nodeToDelete->next;
	delete nodeToDelete;

	return dummy.next;
}

static void print(ListNode* head)
{
	std::cout << "[";
	for (; head; head = head->next)
		std::cout << head->val << " ";

	std::cout << "]\n";
}

void lc_0019()
{
	ListNode* n1 = new ListNode(3, nullptr);
	ListNode* n2 = new ListNode(2, n1);
	ListNode* n3 = new ListNode(1, n2);

	print(n3);
	// removeNthFromEnd(n3, 1);
	// print(n3);
	// removeNthFromEnd(n3, 3);
	n1 = removeNthFromEnd(n1, 1);
	print(n1);
}
