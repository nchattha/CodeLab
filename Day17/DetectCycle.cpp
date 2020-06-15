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

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow, *fast;
    int count = 1;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
   
    if (fast == NULL || fast->next == NULL)
        return NULL;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        
    }
    return slow;
}
int main(void)
{
    ListNode *list1 = new ListNode(3);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(0);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = list1->next;
    
    ListNode *res = detectCycle(list1);
    cout<<"Detection Node: "<<res->val<<endl;
    return 0;
}