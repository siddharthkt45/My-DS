#include <iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        T *S;
        int size;
        int top;
    public:
        Stack()
        {
            size = 10;
            top = -1;
            S = new T[size];
        }
        Stack(int size)
        {
            this->size = size;
            top = -1;
            S = new T[this->size];
        }

        void push(T x);
        T pop();
        T peek(T index);
        int stackTop();
        int isEmpty();
        int isFull();
        void display();
};

template <class T>
void Stack<T>::push(T x)
{
    if(isFull())
        cout << "Stack overflow" << endl;
    else
    {
        top++;
        S[top] = x;
    }
}

template <class T>
T Stack<T>::pop()
{
    T x = -1;
    if(isEmpty())
        cout << "Stack underflow" << endl;
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

template <class T>
T Stack<T>::peek(int index)
{
    T x = -1;
    if(top-index+1 < 0)
        cout << "Invalid index" << endl;
    else
        x = S[top-index+1];

    return x;
}

template <class T>
int Stack<T>::stackTop()
{
    if (isEmpty())
        return -1;
    return S[top];
}

template <class T>
int Stack<T>::isFull()
{
    return top == size - 1;
}

