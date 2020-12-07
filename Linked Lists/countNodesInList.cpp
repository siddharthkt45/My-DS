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

int count(struct Node *p) {
    int c = 0;
    while(p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct Node *p) {
    if(p == 0)
        return 0;
    return count(p->next) + 1;

    // Alternate code snippet for the same approach

    // int x = 0;
    // if(p) {
    //     x = Rcount(p->next);
    //     return x+1;
    // }
    // else
    //     return x;
}

int main() {
    int A[] = {3,5,7,9,11,13,15};

    create(A, 7);

    cout << count(first);

    return 0;
}