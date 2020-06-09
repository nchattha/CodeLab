/**
 * Definition for singly-linked list.
 * 
 */
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    
    ListNode *first = head;
    ListNode *second = head;
    while(second != NULL &&
    second->next != NULL  )
    {
        first = first->next;
        second =second->next->next;
    }

    return first;
}

int main(void)
{
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    for( int i =2; i<7; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;

    }

    temp = head;
    while( temp!= NULL )
    {
        cout<<temp->val<<"\t";
        temp = temp->next;
    }
    cout<<endl;

    ListNode *middle = middleNode(head);
    if( middle!=NULL)
        cout<<"Middle Node: "<<middle->val<<endl;
    else
        cout<<"NULL"<<endl;    
        
    return 0;

}