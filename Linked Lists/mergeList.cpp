#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int B[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    // Iterative method

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    cout << endl;
}

void mergeList(struct Node *p, struct Node *q)
{
    struct Node *last = NULL;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    
    while (p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p)
        last->next = p;
    else
        last->next = q;
}

int main()
{
    int A[] = {2, 4, 6, 8};
    int B[] = {1, 3, 7};

    create(A, 4);
    create2(B, 3);

    display(first);
    display(second);

    mergeList(first, second);

    display(third);

    return 0;
}