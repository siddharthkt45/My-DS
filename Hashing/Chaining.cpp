#include <iostream>
#include "Chains.h"
using namespace std;

int Hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for(i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = Search(HT[Hash(21)], 21);

    if(temp == NULL)
        cout << "Element NOT found\n";
    else
        cout << "Element found: " << temp->data << endl;

    return 0;
}