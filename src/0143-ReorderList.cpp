/*
You are given the head of a singly linked-list.

The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves.
*/

#include "..\tools.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void reorderList(ListNode* head)
{
    if (!head || !head->next || !head->next->next) {
        return;
    }

    // Step 1: Find the middle of the list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    ListNode* head2 = slow->next;
    slow->next = nullptr; // Split the list

    ListNode* prev = nullptr;
    ListNode* curr = head2;
    while (curr) {
        ListNode* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    head2 = prev; // 'prev' is now the new head of the reversed second half

    // Step 3: Merge the two halves
    ListNode* head1 = head;
    while (head2) {
        ListNode* next_node1 = head1->next;
        ListNode* next_node2 = head2->next;

        head1->next = head2;
        head2->next = next_node1;

        head1 = next_node1;
        head2 = next_node2;
    }
}

void lc_0143()
{
    ListNode* n6 = new ListNode(6, nullptr);
    ListNode* n5 = new ListNode(5, n6);
    ListNode* n4 = new ListNode(4, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(2, n3);
    ListNode* n1 = new ListNode(1, n2);
    ListNode* n0 = new ListNode(0, n1);

    reorderList(n0);

    for (auto* i = n0; i; i = i->next)
        std::cout << i->val << " ";

    std::cout << "\n";


}