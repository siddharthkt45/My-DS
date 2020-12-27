#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *st, int size)
{
    cout << "Enter size of stack ";
    cin >> st->size;
    st->top = -1;
    st->S = new Node*[st->size];
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        cout << "Stack overflow\n";
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Node* pop(struct Stack *st)
{
    struct Node x = NULL;
    if (st->top == -1)
        cout << "Stack underflow\n";
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return &x;
}

int peek(struct Stack st, int index)
{
    struct Node x = NULL;
    if (st.top == -1)
        cout << "Invalid Position";
    else
        x = st.S[st.top - index + 1];
    return x;
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    return st.S[st.top];
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}

int isFullStack(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    return 0;
}