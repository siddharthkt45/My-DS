// Reversing Linked List by interchanging elements using auxillary array

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

int count(struct Node *p)
{
    int c = 0;
    while(p) 
    {
        c++;
        p = p->next;
    }
    return c;
}

void create(int A[], int n) 
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseList(struct Node *p)
{
    int *A, i = 0;
    A = new int[count(p)];

    while(p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first, i--;

    while(p)
    {
        p->data = A[i--];
        p = p->next; 
    }
}

int main() 
{
    int A[] = {2,4,6,8};

    create(A, 4);

    display(first);

    reverseList(first);

    display(first);

    return 0;
}