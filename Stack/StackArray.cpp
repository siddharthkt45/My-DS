#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    cout << "Enter size of stack ";
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}

void display(struct Stack st)
{
    for(int i = st.top; i >= 0; i--)
        cout << st.S[i] << " ";
    cout << endl;
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size - 1)
        cout << "Stack overflow\n";
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        cout << "Stack underflow\n";
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top == -1)
        cout << "Invalid Position";
    else
        x = st.S[st.top-index+1];
    return x;
}

int stackTop(struct Stack st)
{
    if(st.top == -1)
        return -1;
    return st.S[st.top];
}

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    return 0;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 34);
    push(&st, 32);
    push(&st, 30);

    cout << pop(&st) << endl;
    display(st);
    return 0;
}