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
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(i = 1; i < n; i++) {
        t = new Node;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p) {
    // Iterative method

    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p) {
    // Recursive method

    if (p != NULL) {
        printf("%d ", p->data);
        display(p->next);
    }
}

void reverseRDisplay(struct Node *p) {
    // Recursive method to print in reverse

    if (p != NULL) {
        reverseRDisplay(p->next);
        printf("%d ", p->data);
    }
}

int main() {
    int A[] = {3,5,7,9,11};

    create(A, 5);

    display(first);

    return 0;
}
