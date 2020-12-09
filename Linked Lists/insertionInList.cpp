#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(int pos, int x) {
    struct Node *t, *p;
    if(pos == 0) {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0) {
        p = first;
        for(int i = 0; i < pos - 1 && p; i++)
            p = p->next;
        if(p) {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";

        p = p->next;
    }
}

int main() {
    int A[] = {3,5,7,9,11,13,15};

    create(A, 7);

    insert(5, 10);

    display(first);

    return 0;
}