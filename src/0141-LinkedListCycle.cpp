/*
    LC 141 Linked List Cycle

    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again
    by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
    Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.
*/

#include "..\tools.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head)
{
    ListNode* p1 = head;
    ListNode* p2 = head;

    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        if (p1 == p2)
            return true;
    }

    return false;
}

void lc_0141()
{
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = root->next;

    printf("%d\n", hasCycle(root));

}