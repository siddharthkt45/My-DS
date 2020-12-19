#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(int x)
{
    struct Node *t = new Node;
    if(t == NULL)
        cout << "Stack is full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }   
}

int pop()
{
    struct Node *t;
    int x = -1;
    if(top == NULL)
        cout << "Stack is Empty" << endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    struct Node *p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    cout << pop() << " ";

    return 0;
}