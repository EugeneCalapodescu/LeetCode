/*
	LC 142. Linked List Cycle II


	Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
	There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
	following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer
	is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

	Do not modify the linked list.

	Example 1:
		Input: head = [3,2,0,-4], pos = 1
		Output: tail connects to node index 1
		Explanation: There is a cycle in the linked list, where tail connects to the second node.

	Floyd Cycle Detection
*/

#include "..\tools.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* detectCycle(ListNode* head)
{
	std::set<ListNode*> s;

	for (; head; head = head->next)
	{
		if (s.find(head) != s.end())
			return head;

		s.insert(head);
	}

	return NULL;
}

ListNode* detectCycleFloyd(ListNode* head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			/* This is the tricky part, to prove that the point where slow and fast meet is at the same distance from
			 * the start of the cycle than the head of the list
			 *
			 * Call M = distance from head to cycle start
			 * call N = length of the cycle
			 * Call K = distance from the starting point of the cycle to the meeting poin
			 *
			 * When Slow and Fast meet:
			 * Slow traveled M + N * C1 + K (head to cycle start, then C1 rounds around the cycle, then K)
			 * Fast traveled M + N * C2 + K
			 *
			 * We also know that Fast travaled 2 times as much as Slow, so
			 * 2*(M + N C1 + K) =  M + N C2 + K    =>
			 * M + N(2C1 - C2) + K = 0 =>
			 * M + K = N(C1 - 2C2) =>
			 * M + K = N * C ( some constant factor of N, the number of nodes in the cycle)
			 * M = NC - K
			 *
			 */
			while (head != slow)
			{
				head = head->next;
				slow = slow->next;
			}
			return head;
		}
	}
	return NULL;
}

void lc_0142()
{
	ListNode* list = NULL;
	auto node = detectCycle(list);

	list = new ListNode(1);
	node = detectCycle(list);

	list = new ListNode(1);
	list->next = new ListNode(2);
	node = detectCycle(list);

	list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = list;
	node = detectCycle(list);


}