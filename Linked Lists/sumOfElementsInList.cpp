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

int add(struct Node *p) {
    int sum = 0;
    while(p) {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int Radd(struct Node *p) {
    if(p == 0) 
        return 0;
    else
        return add(p->next) + p->data;
}

int main() {
    int A[] = {3,5,7,9,11,13,15};

    create(A, 7);

    cout << add(first);

    return 0;
}