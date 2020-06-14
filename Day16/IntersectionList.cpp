#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

int getListLength(ListNode *headA){
    int count = 0 ;
    while( headA != NULL)
    {
        headA = headA->next;
        count++;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    int fLeng = getListLength(headA);
    int sLeng = getListLength(headB);
    int dLeng = abs(fLeng-sLeng);
    if( fLeng == 0 || sLeng == 0 )return NULL;

    if( fLeng > sLeng)
    {
        for( int i = 0 ; i < dLeng ; i++)
            headA = headA->next;
    }
    else if( fLeng < sLeng)
    {
        for( int i = 0 ; i < dLeng ; i++)
            headB = headB->next;
    }

    while( headA != NULL && headB != NULL )
    {
        if( headB->val == headA->val )return headA;
            headA = headA->next;
            headB = headB->next;
    }

    return NULL;

}

ListNode *getIntersectionNodeS(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        if( a == NULL || b == NULL )return NULL;
        
        while( a != b) {
            
            if(a != NULL) 
                a = a->next;
            else 
                a = headB;

            if(b != NULL) 
                b = b->next;
            else 
                b = headA;

            if(a != NULL && b != NULL && a->val == b->val) break;     
        }
        return a;
}
int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    // list1->next->next->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(6);
    list2->next = new ListNode(7);
    list2->next->next = new ListNode(8);
    list2->next->next->next = new ListNode(12);
    list2->next->next->next->next = new ListNode(5);
    list2->next->next->next->next->next = new ListNode(10);

    ListNode *result = getIntersectionNodeS(list1, list2);
    if( result != NULL)
        cout<<"Lists interscet at: "<<result->val<<endl;
    else
        cout<<"Lists DOESN't intersect"<<endl;
    
    return 0;
}