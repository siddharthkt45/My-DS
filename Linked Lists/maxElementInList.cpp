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

int max(struct Node *p) {
    int m = -32768;
    while(p) {
        if(p->data > m) {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int main() {
    int A[] = {3,5,7,9,10,11};

    create(A, 6);

    cout << max(first);
    return 0;
}