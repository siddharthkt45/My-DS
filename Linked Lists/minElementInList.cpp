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

int min(struct Node *p) {
    int m = INT32_MAX;
    while(p) {
        if(m > p->data)
            m = p->data;
        
        p = p->next;
    }
    return m;
}

int Rmin(struct Node *p) {
    int x = 0;
    if(p == 0) 
        return INT32_MAX;
    else {
        x = Rmin(p->next);
        if(x < p->data)
            return x;
        else
            return p->data;
    }

    // int x = 0;
    // if (p == 0)
    //     return INT32_MAX;
    
    // x = Rmin(p->next);
    // return x < p->data ? x : p->data;    
}

int main() {
    int A[] = {3,5,7,9,11,13,15};

    create(A, 7);

    cout << min(first);

    return 0;
}