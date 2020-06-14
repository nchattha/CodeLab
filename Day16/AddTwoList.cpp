/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 */
#include<iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if( l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    int carry = 0;
    ListNode *fList = l1;
    ListNode *sList = l2;
    ListNode *prev;
    while( fList != NULL && sList != NULL)
    {
        fList->val += (sList->val+carry);
        carry = (fList->val/10);
        fList->val %= 10;
        prev = fList;
        fList = fList->next;
        sList = sList->next;
    }

    if( sList != NULL ){
        prev->next = sList; 
        fList = sList;
    }

    while(fList != NULL)
    {
        fList->val+= carry;
        carry = (fList->val/10);
        fList->val %= 10;
        prev = fList;
        fList = fList->next;
    }

    if( carry != 0)
    {
        prev->next = new ListNode(carry);
    }

    return l1;
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

int main(void)
{
    ListNode *list1 = new ListNode(1);
    // list1->next = new ListNode(4);
    // list1->next->next = new ListNode(3);
    
    ListNode *list2 = new ListNode(9);
    list2->next = new ListNode(9);
    // list2->next->next = new ListNode(4);
    
    printList(list1);
    printList(list2);
    ListNode *res = addTwoNumbers(list1, list2);
    cout<<"Sum Of Two List"<<endl;
    printList(res);
    return 0;
}