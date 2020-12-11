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

bool checkSorted(struct Node *p) {
    int x = INT16_MIN;
    while (p != NULL)
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

int main() {
    int A[] = {3,5,7,9,11,13,15};

    create(A, 7);

    bool check = checkSorted(first);

    if(check == 1)
        cout << "Sorted";
    else
        cout << "Not sorted";

    return 0;
}