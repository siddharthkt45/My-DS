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

void insertLast(int x) {
    struct Node *t = new Node;
    struct Node *last = first;
    t->data = x;
    t->next = NULL;
    while (last->next)
        last = last->next;
    if(first == NULL)
        first = last = t;
    else {
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while(p) {
        cout << p->data << " ";

        p = p->next;
    }
}

int main() {
    int A[5];
    
    insertLast(17);

    display(first);

    return 0;
}