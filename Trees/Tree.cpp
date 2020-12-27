#include <iostream>
#include "Queue.h"
// #include "Stack.h"
using namespace std;

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

// void IPreorder(struct Node *p)
// {
//     struct Stack st;
//     createStack(&st, 100);
//     while (p || !isEmptyStack(st))
//     {
//         if(p)
//         {
//             cout << p->data << " ";
//             push(&st, p);
//             p = p->lchild;
//         }
//         else
//         {
//             p = pop(&st);
//             p = p->rchild;
//         }
//     }
// }

// void IInorder(struct Node *p)
// {
//     struct Stack st;
//     createStack(&st, 100);
//     while(p || !isEmptyStack(st))
//     {
//         if(p)
//         {
//             push(&st, p);
//             p = p->lchild;
//         }
//         else
//         {
//             p = pop(&st);
//             cout << p->data;
//             p = p->rchild;
//         }
//     }
// }

void Preorder(struct Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    cout << root->data << " ";
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            cout << root->lchild->data << " ";
            enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            cout << root->rchild->data << " ";
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    createTree();
    printf("Pre Order ");
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    printf("\nLevel Order ");
    Levelorder(root);
    printf("\nHeight ");
    cout << height(root) << "Count " << count(root);

    // IPreorder(root);
    // IInorder(root);

    return 0;
}