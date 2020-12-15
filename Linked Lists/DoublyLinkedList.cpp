#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > Length(p))
        return;
    struct Node *t;

    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(first == NULL)
        {
            t->next = t->prev = NULL;
            first = t;
        }
        else
        {
            t->next = first;
            t->prev = NULL;
            first->prev = t;
            first = t;
        } 
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }  
}

int Delete(struct Node *p, int index)
{
    int x = -1;

    if(index < 1 || index > Length(p))
        return -1;
    
    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;

        if(p->next)
            p->next->prev = p->prev;
        
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;

        if(p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int A[] = {2,4,6,8,10};

    Create(A, 5);

    Display(first);

    // cout << "Length is: " << Length(first);

    // Insert(first, 0, 0);

    // cout << "Deleted element is: " << Delete(first, 1) << endl;

    Reverse(first);

    Display(first);

    return 0;
}