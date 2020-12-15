#include<iostream>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node *next;
};

template <class T>
class LinkedList
{
    protected:
        Node<T> *first;
    public:
        LinkedList() 
        {
            first = NULL;
        }
        LinkedList(T A[], int n);
        
        void Display();
        void Insert(int index, T x);
        void InsertLast(T x);
        T Delete(int index);
        int Length();
        // void RecursiveReverse(Node<T> *a, Node<T> *b);
        Node<T> *Search(int x);
        Node<T> *RSearch(int x); 
        void ReverseList();
        void ReverseListLinks();

        ~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *t, *last;
    int i = 0;

    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

template <class T>
int LinkedList<T>::Length()
{
    Node<T> *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

template <class T>
void LinkedList<T>::Display()
{
    Node<T> *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::Insert(int index, T x)
{
    if(index < 0 || index > Length())
        return;

    Node<T> *t, *p = first;

    t = new Node<T>;
    t->data = x;

    if(index == 0) // Inserting before the first Node
    {
        t->next = first;
        first = t;
    }
    else if(index > 0)
    {
        for(int i = 0; i < index-1; i++)
            p = p->next;
        
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

template <class T>
void LinkedList<T>::InsertLast(T x)
{
    Node<T> *t = new Node<T>;
    Node<T> *last = first;
    t->data = x;
    t->next = NULL;
    while(last->next)
        last = last->next;
    if(first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
    
}

template <class T>
T LinkedList<T>::Delete(int index)
{
    Node<T> *p, *q = NULL;
    int x = -1;

    if(index < 1 || index > Length())
        return -1;
    
    if(index == 1) // Deleting first Node
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for(int i = 0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }

        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    
    return x;
}

template <class T>
void LinkedList<T>::ReverseListLinks()
{
    Node<T> *p = first, *r = NULL, *q = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

template <class T>
void LinkedList<T>::ReverseList()
{
    Node<T> *p = first;
    int *A, i = 0;
    A = new int[Length()];

    while (p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    p = first;
    i--;

    while (p)
    {
        p->data = A[i--];
        p = p->next;
    }
}

// template <class T>
// void LinkedList<T>::RecursiveReverse(Node<T> *q, Node<T> *p)
// {
//     if (p != NULL)
//     {
//         recursiveReverse(p, p->next);
//         p->next = q;
//     }
//     else
//     {
//         first = q;
//     }
// }

int main() 
{
    int A[] = {1,2,3,4,5};
    LinkedList<int> l(A, 5);
    // l.Insert(0,19);
    // cout << l.Length() << endl;
    // int x = l.Delete(1);
    // cout << x << endl;
    // l.RecursiveReverse(NULL, first);
    // l.Display();
    l.Display();

    return 0;
}