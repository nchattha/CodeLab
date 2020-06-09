/*Design a stack that supports push, pop, top, and 
retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.*/
#include <iostream>
using namespace std;
class MinStack
{
    struct NodeElement
    {
        int value;
        int minValue;
        NodeElement *next;
        NodeElement *prev;
        NodeElement(int val, int minVal) : value(val),
                                           minValue(minVal)
        {
            next = NULL;
            prev = NULL;
        }
    };

    NodeElement *currentNode;

public:
    MinStack()
    {
        currentNode = NULL;
    }

    void push(int x)
    {
        if (currentNode == NULL)
            currentNode = new NodeElement(x, x);
        else
        {
            //CREATE the current node
            NodeElement *newNode = new NodeElement(x, x < currentNode->minValue ? x : currentNode->minValue);
            //Link the new node to the previous node
            newNode->prev = currentNode;
            //Link new node the current node
            currentNode->next = newNode;
            // update the curernt node pointer
            currentNode = newNode;
        }
    }

    void pop()
    {
        if (currentNode != NULL)
        {
            //store the current node
            NodeElement *temp = currentNode;
            //update the current node
            currentNode = currentNode->prev;
            //delete the top element
            delete temp;
            temp = NULL;
        }
    }

    int top()
    {
        if (currentNode != NULL)
            return currentNode->value;

        return -1;
    }

    int getMin()
    {
        if (currentNode != NULL)
            return currentNode->minValue;

        return -1;
    }
};

int main(void)
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    cout << "TOP: " << obj->top() << endl;
    obj->push(0);
    cout << "TOP: " << obj->top() << endl;
    obj->push(3);
    cout << "TOP: " << obj->top() << endl;
    cout << "MIN: " << obj->getMin() << endl;
    obj->pop();
    cout << "TOP: " << obj->top() << endl;
    cout << "MIN: " << obj->getMin() << endl;
    return 0;
}
