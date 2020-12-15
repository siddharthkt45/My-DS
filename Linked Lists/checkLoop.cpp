#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

bool isLoop(struct Node *f)
{
    struct Node *p = f, *q = f;
    do
    {
        p = p->next;
        q = q->next;
        if(q)
            q = q->next;
    } while (p && q && p != q);
    
    if(p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *t1, *t2;

    int A[] = {2,4,6,8,10,12};
    create(A, 6);

    t1 = first->next->next;
    t2 = first->next->next->next->next->next;

    t2->next = t1;

    cout << isLoop(first);

    return 0;
}