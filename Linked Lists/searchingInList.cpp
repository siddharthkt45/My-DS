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

struct Node * search(struct Node *p, int key) {
    struct Node *q = NULL;
    while(p) {
        if(key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * Rsearch(struct Node *p, int key) {
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return Rsearch(p->next, key);
}

void display(struct Node *p) {
    while(p) {
        cout << p->data << " ";

        p = p->next;
    }
}

int main() {
    struct Node *temp;
    int A[] = {3,5,7,9,10,13};

    create(A, 6);

    temp = search(first, 9);
    if(temp)
        cout << "Key is found " << temp->data << endl;
    else
        cout << "Key is not found" << endl;

    display(first);

    return 0;
}