//
// Created by Laila Nasser ElKoussy 900160812 on 11/19/17.
//

#include "QueueL.h"
#include <iostream>
using namespace std;

// Class Constructor
template <class Type>
QueueL<Type>::QueueL()
{
    front = NULL; rear = NULL; count = 0;
}

// Copy Constructor
template <class Type>
QueueL<Type>::QueueL(const QueueL <Type> & original)
{
    front = NULL; rear = NULL; count = 0;
    if (!original.queueIsEmpty())
    {
        NodePointer cursor = original.front;
        for (int i = 1; i <= original.queueLength(); i++)
        {
            enqueue(cursor->e);
            cursor = cursor->next;
        }
    }

}

// Class Destructor
template <class Type>
QueueL<Type>::~QueueL()
{
    //Make list empty
    Type v;
    while (front != NULL)
        dequeue(v);
}


// Add a node with data (v) at the rear of the queue;
// the new node becomes the rear node.
template <class Type>
void QueueL<Type>::enqueue(Type v)
{
    NodePointer pnew = new node;
    pnew->e = v;  pnew->next = NULL;
    if (queueIsEmpty())
    {
        front = pnew;
        rear = pnew;
    }
    else
    {
        rear->next = pnew;
        rear = pnew;
    }
    count++;
}

// dequeue front node. Next node becomes front node.
template <class Type>
void QueueL<Type>::dequeue(Type &v)
{
    NodePointer cursor;
    if (queueIsEmpty()) cout << "Queue is Empty" << endl;
    else
    {
        v = front->e;
        cursor = front;
        front = front->next;
        delete cursor;
        count--;
        if (count == 0)
            rear = NULL;
    }
}

// Retrieve front node without removing it
template <class Type>
void QueueL<Type>::queueFront(Type &v) const
{
    NodePointer cursor;
    if (queueIsEmpty()) cout << "Queue is Empty" << endl;
    else { v = front->e; }
}

// return True if queue is empty
template <class Type>
bool QueueL<Type>::queueIsEmpty() const
{
    return (count == 0);
}

// Queue Length
template <class Type>
int QueueL<Type>::queueLength() const
{
    return count;
}
