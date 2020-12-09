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

void display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";

        p = p->next;
    }
    cout << endl;
}

int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Delete(struct Node *p, int pos) {
    struct Node *q = NULL;
    int x = -1, i;
    if(pos < 1 || pos > count(p))
        return x;

    if(pos == 1) {
        first = first->next;
        x = p->data;
        delete p;
    }
    else {
        for(i = 0; i < pos-1 && p; i++) {
            q = p;
            p = p->next;
        }
        if(p) {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

int main() {
    int A[] = {10,20,30,40,50};

    create(A, 5);

    display(first);

    Delete(first, 4);

    display(first);

    return 0;
}