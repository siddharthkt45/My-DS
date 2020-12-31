#include <iostream>
using namespace std;

void Insert(int H[], int n)
{
    int temp, i = n;
    temp = H[n];

    while(i > 1 && temp > H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }

    H[i] = temp;
}

int Delete(int H[], int n)
{
    int x, i, j, temp, val;
    val = H[1];
    x = H[n];
    H[1] = H[n];
    H[n] = val;
    i = 1;
    j = i * 2;

    while(j < n-1)
    {
        if(H[j+1] > H[j])
            j = j + 1;
        if(H[i] < H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2 * j;
        }
        else 
            break;
    }
    return val;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    // 40,25,35,10,5,20,30
    int i;

    for(i = 2; i <= 7; i++)
        Insert(H, i);

    // Heap Sort
    for(i = 7; i > 1; i--)
        Delete(H, i);

    // cout << "Deleted value is: " << Delete(H, 7) << endl;
    // cout << "Deleted value is: " << Delete(H, 6) << endl;

    for(i = 1; i <= 7; i++)
        cout << H[i] << " ";
    cout << endl;
    return 0;
}