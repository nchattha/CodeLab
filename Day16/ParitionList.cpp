/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *lHead, *lTail;
    ListNode *rHead, *rTail;
    lHead = lTail = rHead = rTail = NULL;
    if (x > 0 || head != NULL)
    {
        while (head != NULL)
        {
            if (head->val < x)
            {
                if (lHead == NULL)
                    lHead = lTail = head;
                else
                {
                    lTail->next = head;
                    lTail = head;
                }
            }
            else
            {
                if (rHead == NULL)
                    rHead = rTail = head;
                else
                {
                    rTail->next = head;
                    rTail = head;
                }
            }
            head = head->next;
        }

        if (rHead != NULL && lHead == NULL)
        {
            rTail->next = NULL;
            head = rHead;
        }
        else if (rHead == NULL && lHead != NULL)
        {
            lTail->next = NULL;
            head = lHead;
        }
        else if (rHead != NULL && lHead != NULL)
        {
            rTail->next = NULL;
            lTail->next = rHead;
            head = lHead;
        }
        else
        {
            return NULL;
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
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(2);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(2);
    printList(list1);
    ListNode *head = partition(list1, 3);
    cout << "Partition List " << endl;
    printList(head);

    return 0;
}