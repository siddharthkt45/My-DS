#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

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

void concatList(struct Node *p)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
}

int main()
{
    int A[] = {1,2,3,4};
    int B[] = {5,6,7};

    create(A, 4);
    create2(B, 3);

    display(first);
    display(second);

    concatList(first);

    display(first);

    return 0;
}