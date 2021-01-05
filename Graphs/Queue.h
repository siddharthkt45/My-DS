#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node;
    if(t == NULL)
        cout << "Queue is Full" << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }   
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        cout << "Queue is empty";
    else
    {
        t = front;
        x = front->data;
        front = front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}