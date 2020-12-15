#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->prev = head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        head->prev = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
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
        if(head == NULL)
        {
            head = t;
            t->next = t->prev = head;
        }
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev = t;
            t->prev->next = t;
            head = t;
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
    if(index < 1 || index > Length(p))
        return -1;

    int x = -1;
    if(index == 1)
    {
        head = head->next;
        x = p->data;
        p->prev->next = head;
        if(head)
            head->prev = p->prev;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};

    Create(A, 5);

    Display(head);

    // cout << "Length is: " << Length(first);

    // Insert(head, 5, 0);

    // cout << "Deleted element is: " << Delete(first, 1) << endl;

    // Reverse(first);

    cout << Delete(head, 5) << endl;

    Display(head);

    return 0;
}