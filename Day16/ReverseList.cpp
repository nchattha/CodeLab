#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseList(ListNode* head) {
    ListNode *prev, *curr, *next;
    prev = curr = next = NULL;

    if( head != NULL)
    {
        curr = head;
        while ( curr != NULL )
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    return head;
}


int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    ListNode *head = reverseList(list1);
    cout<<"Reserve List "<<endl;
    while( head != NULL)
    {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}