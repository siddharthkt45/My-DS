#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void RDisplay(struct Node *p)
{
    static int flag = 0;

    if(p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > Length(p))
        return;

    struct Node *t;

    if(index == 0)
    {
        t = new Node;
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    int x;
    if(index < 1 || index > Length(head))
        return -1;
    struct Node *q;
    if(index == 1)
    {
        while(p->next != head)
            p = p->next;
        x = head->data;
        if(p == head) // which means there is only one node in the LinkedList
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for(int i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

void ReverseLinks(struct Node *p)
{
    struct Node *r = NULL, *q = NULL;
    do
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } while (p != head);
    head = q;
}

void Reverse(struct Node *p)
{
    int *A, i = 0;
    A = new int[Length(p)];

    do
    {
        A[i] = p->data;
        p = p->next;
        i++;
    } while (p != head);

    p = head, i--;

    do
    {
        p->data = A[i--];
        p = p->next;
    } while (p != head);
}

bool IsSorted(struct Node *p)
{
    int x = INT16_MIN;
    do
    {
        if(p->data < x)
            return false;
        x = p->data;
        p = p->next;
    } while (p != head);
    return true;
}

int main()
{
    int A[] = {2,4,6,8,10};

    Create(A, 5);

    Display(head);

    // Insert(head, 0, 0);

    // cout << Delete(head, 5) << endl;

    // Reverse(head);

    if (IsSorted(head) == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
        
    Display(head);

    return 0;
}