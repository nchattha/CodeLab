/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *slow, *fast, *prev = NULL;

    if (head != NULL)
    {
        slow = fast = head;
        //move fast pointer by ntime
        while (n > 0 && fast != NULL)
        {
            fast = fast->next;
            n--;
        }

        //move the slow and fast both
        while (fast != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // cout<<prev->val<<" : "<<slow->val<<" : "<<fast->val<<endl;
        //link the prev node to the next node
        if (slow != NULL)
        {
            if (prev == NULL)
                head = slow->next;
            else
                prev->next = slow->next;

            delete slow;
            slow = NULL;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    printList(list1);
    ListNode *head = removeNthFromEnd(list1, 0);
    cout << "Updated List " << endl;
    printList(head);

    return 0;
}